/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/22 22:49:43 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lem_in(t_lem *lem)
{
	draw_graph(lem);
	while (!lem->vis->quit)
	{
		while (SDL_PollEvent(&lem->vis->e) != 0)
		{
			if (lem->vis->e.type == SDL_QUIT)
				lem->vis->quit = 1;
			else if (lem->vis->e.type == SDL_KEYDOWN)
			{
				if (lem->vis->e.key.keysym.sym == SDLK_ESCAPE)
					lem->vis->quit = 1;
			}
		}
	}
}

int				main(int ac, char **av)
{
	t_lem	*lem;
	t_ant	*army;
//	int		fd;

//	fd = open("tests/test_from_smight", O_RDONLY);
	lem = create_lem(0);
	army = create_army(lem->ant_c);
	ac > 1 ? check_flags(av, lem) : 0;
	!lem->without_map ? ft_printf("%s\n", lem->map) : 0;
	init_vis(lem);
	draw_graph(lem);
	sleep(3);
	find_optimal_path(lem, army);
	offensive(lem, army);
	lem_in(lem);
	ft_del_lem(&lem);
	return (0);
}


