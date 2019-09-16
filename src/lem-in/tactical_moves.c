/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactical_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:15:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/16 15:41:06 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		tactical_moves(t_lem *lem, t_ant *army, t_listpath *listpath)
{
	t_listpath	*cur_path;
	t_ant		*soldier;
	int			reserve;

	reserve = lem->ant_c;
	soldier = army;
	while (soldier)
	{
		cur_path = listpath;
		while (cur_path && soldier)
		{
			soldier->path = cur_path->path;
			soldier = soldier->next;
			reserve--;
			cur_path = cur_path->next;
			if (!cur_path || cur_path->path_len > lem->ant_c)
				break ;
		}
	}
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
	int		veterans;
	int		in_battle;
	int		reserve;

	reserve = lem->ant_c;
	in_battle = 0;
	veterans = 0;
	while (army)
	{
		if (reserve > lem->path_c)
		{
			in_battle += lem->path_c;
			reserve -= lem->path_c;
		}
		else
		{
			in_battle += reserve;
			reserve = 0;	
		}
		//ft_printf("in battle = %d, reserve = %d\n", in_battle, reserve);
		step_to_win(army, in_battle);
		in_battle -= soldiers_commission(&army);
	}
}
