/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/24 18:12:40 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lem_in(t_lem *lem)
{
	while (!lem->vis->quit && !lem->vis->run)
	{
		while (SDL_PollEvent(&lem->vis->e) != 0)
		{
			if (lem->vis->e.type == SDL_QUIT)
				lem->vis->quit = 1;
			else if (lem->vis->e.type == SDL_KEYDOWN)
			{
				if (lem->vis->e.key.keysym.sym == SDLK_RETURN)
					lem->vis->run = 1;
				if (lem->vis->e.key.keysym.sym == SDLK_ESCAPE)
					lem->vis->quit = 1;
				//ft_printf("quit = %d, return = %d\n", lem->vis->quit, lem->vis->run);
			}
		}
	}
}

int				main(int ac, char **av)
{
	t_lem	*lem;
	t_ant	*army;
	int		fd;

	fd = open("tests/sferical_test_in_vacuum", O_RDONLY);
	lem = create_lem(fd);
	army = create_army(lem->ant_c);
	ac > 1 ? check_flags(av, lem) : 0;
	!lem->without_map ? ft_printf("%s\n", lem->map) : 0;
	if (lem->visualization)
	{
		init_vis(lem);
		lem->design_map ? design_map(lem) : 0;
		lem_in(lem);
		draw_graph(lem, NULL);
	}
	find_optimal_path(lem, army);
	offensive(lem, army);
	lem->visualization ? lem_in(lem) : 0;
	ft_del_lem(&lem);
	return (0);
}


