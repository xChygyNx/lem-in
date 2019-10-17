/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/17 14:13:21 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int		main(int ac, char *av[])
{
	t_lem	*lem;
	t_ant	*army;
	//структура для визуализации
	t_visual	*vis;
	int			fd;

	fd = open("tests/flow_ten", O_RDONLY);
	lem = create_lem(fd);
	army = create_army(lem->ant_c);
	ac == 2 && !ft_strcmp(av[1], "-wm") ? 0 : ft_printf("%s\n", lem->map);
	find_optimal_path(lem, army);
	offensive(lem, army);
	ft_del_lem(&lem);
	vis = init();
	SDL_FillRect(vis->surface, NULL, SDL_MapRGB(vis->surface->format, 0x00, 0x00, 0x00));
	//обновляем изображение в окне (без этого нарисованное нами изображение не появится на экране)
	SDL_UpdateWindowSurface(vis->window);
	//ждем пока пользователь не закроет окно
	while (!vis->quit)
	{
		//достаем следующее событие из стека событий
		while (SDL_PollEvent(&vis->event) != 0)
			if (vis->event.type == SDL_QUIT)
				vis->quit = 1;
		SDL_SetRenderDrawColor(vis->render, 0xFF, 0xFF, 0xFF, 0xFF);
	}
	//освобождаем изображение
	SDL_FreeSurface(vis->surface);
	vis->surface = NULL;
	//Уничтожить окно
	SDL_DestroyWindow(vis->window);
	vis->window = NULL;
	//выйти из  SDL
	SDL_Quit();
	return (0);
}
