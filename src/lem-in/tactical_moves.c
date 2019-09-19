/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactical_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:15:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/19 17:42:48 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void		step_to_win(t_ant *army, int number)
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
	int		steps;

	steps = routing(lem->listpath, &army);
	while (army)
	{
		meat = go_to_fight(lem->listpath, army);
		step_to_win(army, meat);
		soldiers_commission(&army);
	}
}
