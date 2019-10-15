/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/15 21:40:20 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int		main(int ac, char *av[])
{
	t_lem	*lem;
	t_ant	*army;
	// SDL окно
	SDL_Window *gWindow;
	// я так понял аналог image
	SDL_Surface	*screenSurface;

	lem = create_lem(0);
	army = create_army(lem->ant_c);
	ac == 2 && !ft_strcmp(av[1], "-wm") ? 0 : ft_printf("%s\n", lem->map);
	find_optimal_path(lem, army);
	offensive(lem, army);
	ft_del_lem(&lem);
	gWindow = NULL;
	screenSurface = NULL;
	//инициализация sdl, я так понимаю флаг sdl_init_video нам больше всего подходит
	if ((SDL_Init(SDL_INIT_VIDEO)) < 0)
		ft_exit (&lem, SDL_INIT_ERR);
	else
	{
		gWindow = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
		//ft_printf("window = %p\n", gWindow);
		if (gWindow == NULL)
			ft_exit(&lem, WIN_ERROR);
		else
		{
			//получаем изображение их окна
			screenSurface = SDL_GetWindowSurface(gWindow);
			//заполняем изображение цветом
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
			//обновляем изображение в окне (без этого нарисованное нами изображение не появится на экране)
			SDL_UpdateWindowSurface(gWindow);
			//делаем задержку, чтобы окно после исполнения команд не исчезло)
			SDL_Delay(10000);
		}
		//освобождаем изображение
		SDL_FreeSurface(screenSurface);
		screenSurface = NULL;
		//Уничтожить окно
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		//выйти из  SDL
		SDL_Quit();
	}
	return (0);
	return (0);
}
