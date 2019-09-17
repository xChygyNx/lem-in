/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/17 16:07:55 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;
	t_ant	*army;

	fd = open("tests/test_in_vacuum_plus_long_way", O_RDONLY);
	lem = create_lem(fd);
	suurballe(lem);
//	ft_print_paths(lem->listpath);
	army = create_army(lem->ant_c);
	//прими свой путь боец1
	tactical_moves(lem, army, lem->listpath);
	//НАСТУПААААААЕЕЕЕЕЕЕЕМ
	offensive(lem, army);
//	pereklichka(army);
	ft_del_lem(&lem);
	return (0);
}
