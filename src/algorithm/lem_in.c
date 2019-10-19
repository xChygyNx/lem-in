/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/19 17:32:41 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		lem_in(t_lem *lem, t_ant *army)
{
	find_optimal_path(lem, army);
	offensive(lem, army);

	//обновляем изображение в окне
	//без этого нарисованное нами изображение не появится на экране
	SDL_UpdateWindowSurface(lem->vis->win);
	//ждем пока пользователь не закроет окно
	while (!lem->vis->quit)
	{
		//достаем следующее событие из стека событий
		while (SDL_PollEvent(&lem->vis->e) != 0)
			if (lem->vis->e.type == SDL_QUIT)
				lem->vis->quit = 1;
			else if (lem->vis->e.type == SDL_KEYDOWN)
			{
				if (lem->vis->e.key.keysym.sym == SDLK_ESCAPE)
					lem->vis->quit = 1;
			}
	}
}

int				main(int ac, char **av)
{
	t_lem	*lem;
	t_ant	*army;
	int		fd;

	fd = open("tests/flow_ten", O_RDONLY);
	lem = create_lem(fd);
	army = create_army(lem->ant_c);
	ac == 2 && !ft_strcmp(av[1], "-wm") ? 0 : ft_printf("%s\n", lem->map);
	init_vis(lem);
	lem_in(lem, army);
	ft_del_lem(&lem);
	return (0);
}


