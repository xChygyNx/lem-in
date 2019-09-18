/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/18 22:15:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;
	t_ant	*army;

//	fd = open("tests/flow_thousand", O_RDONLY);
	lem = create_lem(0);
	army = create_army(lem->ant_c);
	find_optimal_path(lem, &army);
//	ft_print_paths(lem->listpath);
	//прими свой путь боец1
//	tactical_moves(lem, army, lem->listpath);
	//НАСТУПААААААЕЕЕЕЕЕЕЕМ
//	pereklichka(army);
	ft_del_lem(&lem);
	return (0);
}
