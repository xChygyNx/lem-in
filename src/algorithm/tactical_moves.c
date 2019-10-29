/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactical_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:15:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/29 15:15:31 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			almost_complete_mission(t_ant *army, int meat)
{
	int		heroes;

	heroes = 0;
	while (army && meat--)
	{
		if (army->path->next->vrx->type == END)
			heroes++;
		army = army->next;
	}
	return(heroes);
}

static int	go_to_fight(t_listpath *paths, t_ant *army)
{
	int		column_c;

	column_c = 0;
	while (army)
	{
		column_c++;
		if (army->path == paths->path)
			break ;
		army = army->next;
	}
	return (column_c);
}

static void	step_to_win(t_ant *army, int number)
{
	while (army && number)
	{
		army->path = army->path->next;
		ft_printf("L%d-%s", army->serial_number, army->path->vrx->name);
		number--;
		army = army->next;
		army ? ft_printf(" ") : 0;
	}
	ft_printf("\n");
}

void		offensive(t_lem *lem, t_ant *army)
{
	int		meat;
	int		veterans;
	int		fresh_meat;
	int		heroes;

	routing(lem->listpath, army);
	veterans = 0;
	while (army->prev)
		army = army->prev;
	while (army)
	{
		meat = go_to_fight(lem->listpath, army);
		heroes = almost_complete_mission(army, meat);
		fresh_meat = meat - veterans + heroes;
		//ft_printf("meat = %d, fresh meat = %d, veterans = %d, heroes = %d\n", meat, fresh_meat, veterans, heroes);
		veterans = meat;
		if (lem->visual)
			draw_move_ants(lem, army, meat, fresh_meat);
		step_to_win(army, meat);
		soldiers_commission(&army);
	}
}
