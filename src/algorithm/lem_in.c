/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/22 19:56:36 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lem_in(t_lem *lem)
{
	margin_vertex(lem);
	draw_graph(lem);
	SDL_RenderPresent(lem->vis->render);
	//ждем пока пользователь не закроет окно
	while (!lem->vis->quit)
	{
		//достаем следующее событие из стека событий
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
	find_optimal_path(lem, army);
	offensive(lem, army);
	lem_in(lem);
	ft_del_lem(&lem);
	return (0);
}


