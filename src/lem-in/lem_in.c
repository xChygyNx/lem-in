/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/16 19:32:06 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;
	t_ant	*army;

//	fd = open("tests/test_from_smight", O_RDONLY);
	lem = create_lem(0);
	suurballe(lem);
//	ft_print_paths(lem->listpath);
	army = create_army(lem->ant_c);
	//прими свой путь боец
	tactical_moves(lem, army, lem->listpath);
	//НАСТУПААААААЕЕЕЕЕЕЕЕМ
	offensive(lem, army);
//	pereklichka(army);
	ft_del_lem(&lem);
	return (0);
}
