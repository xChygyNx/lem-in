/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactical_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:15:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/17 17:05:19 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


static int	count_less_paths(t_listpath *list, t_listpath *path)
{
	int		path_c;
	//t_path	*begin;

	//begin = listpath->path;
	path_c = 0;
	while (path && path != list)
	{
		path_c++;
		list = list->next;
	}
	return (path_c);
}

void		tactical_moves(t_lem *lem, t_ant *army, t_listpath *listpath)
{
	t_listpath	*cur_path;
	t_ant		*soldier;
	int			reserve;
	int			less_c;

	reserve = lem->ant_c;
	soldier = army;
	while (soldier)
	{
		cur_path = listpath;
		while (cur_path && soldier && reserve)
		{
			soldier->path = cur_path->path;
			soldier = soldier->next;
			reserve--;
			cur_path = cur_path->next;
			less_c = count_less_paths(listpath, cur_path);
			if (!cur_path || cur_path->path_len * less_c > reserve)
				break ;
		}
	}
}

static int go_to_fight(t_listpath *paths, int reserve)
{
	int		column_c;

	column_c = 0;
	while (reserve && paths && paths->path_len * column_c < reserve)
	{
		column_c++;
		paths = paths->next;
		reserve--;
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
	int		veterans;
	int		in_battle;
	int		reserve;
	int		meat;

	reserve = lem->ant_c;
	in_battle = 0;
	veterans = 0;
	while (army)
	{
		meat = go_to_fight(lem->listpath, reserve);
		//if (reserve > meat)
		in_battle += meat;
		reserve -= meat;
		/*}
		else
		{
			in_battle += reserve;
			reserve = 0;	
		}*/
		//ft_printf("in battle = %d, reserve = %d\n", in_battle, reserve);
		//print_clm = print_column(lem->listpath, reserve);
		step_to_win(army, in_battle);
		in_battle -= soldiers_commission(&army);
	}
}
