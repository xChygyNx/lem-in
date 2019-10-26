/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/26 16:10:22 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			visual_mode(t_lem *lem, t_ant *army)
{
	initilize_visio(lem);
	draw_graph(lem, NULL, 1);
	find_optimal_path(lem, army);
	lem->vis->delay = 5;
	offensive(lem, army);
}

int				main(int ac, char **av)
{
	t_lem	*lem;
	t_ant	*army;
	//int		fd;

	//fd = open("tests/test_from_smight", O_RDONLY);
	lem = create_lem(0);
	army = create_army(lem->ant_c);
	ac > 1 ? check_flags(av, lem) : 0;
	!lem->without_map ? ft_printf("%s\n", lem->map) : 0;
	if (lem->visual)
		visual_mode(lem, army);
	else
	{
		find_optimal_path(lem, army);
		offensive(lem, army);
	}
	ft_del_lem(&lem);
	return (0);
}
