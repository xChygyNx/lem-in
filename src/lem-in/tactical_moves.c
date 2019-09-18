/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactical_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:15:57 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/18 22:10:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


/*static int	count_less_paths(t_listpath *list, t_listpath *path)
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
	char		eq_prev;

	reserve = lem->ant_c;
	soldier = army;
	while (soldier)
	{
		cur_path = listpath;
		//reserve_st = reserve;
		while (cur_path && soldier && reserve)
		{
			soldier->path = cur_path->path;
			soldier = soldier->next;
			reserve -= cur_path ? 1 : 0;
			eq_prev = cur_path->next &&\
				cur_path->path_len == cur_path->next->path_len ? 1 : 0;
			cur_path = cur_path->next;
			less_c = count_less_paths(listpath, cur_path);
			if ((!cur_path || cur_path->path_len * less_c > reserve) && !eq_prev)
				break ;
		}
	}
}*/

static int go_to_fight(t_listpath *paths, t_ant *army)
{
	int				column_c;
	//static int		repetition;
	//char			new_repetition;
	//int				circle;

	column_c = 0;
	//circle = 0;
	//new_repetition = veterans ? 0 : 1;
	//repetition += new_repetition;
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
	//char	veterans;
	//int		in_battle;
	//int		reserve;
	int		meat;
	int		steps;

	//reserve = lem->ant_c;
	//in_battle = 0;
	//veterans = 0;
	//высчитывает количество ходов + инвертирует army т.к. она собиралась
	//в обратном порядке, а дальше с ней удобно работать в
	//правильном порядке (от 1 до ant_c)
//	ft_print_paths(lem->listpath);
	steps = routing(lem->listpath, &army);
//	ft_printf("min_steps = %d\n", steps);
	while (army)
	{
		meat = go_to_fight(lem->listpath, army);
		//in_battle += meat;
		//reserve -= meat;
		step_to_win(army, meat);
		soldiers_commission(&army);
		//in_battle -= veterans;
	}
}

/*void		offensive(t_lem *lem, t_ant *army)
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
		}
		else
		{
			in_battle += reserve;
			reserve = 0;
		}
		//ft_printf("in battle = %d, reserve = %d\n", in_battle, reserve);
		//print_clm = print_column(lem->listpath, reserve);
		step_to_win(army, in_battle);
		in_battle -= soldiers_commission(&army);
	}
}*/
