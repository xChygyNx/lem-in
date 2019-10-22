/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:27:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/22 16:21:45 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "/Users/pcredibl/.brew/Cellar/sdl2_gfx/1.0.4/include/SDL2/SDL2_gfxPrimitives.h"

void		ft_free_visual(t_visual **vis)
{
	if (vis && *vis)
	{
		SDL_FreeSurface((*vis)->surface);
		(*vis)->surface = NULL;
		SDL_DestroyWindow((*vis)->win);
		(*vis)->win = NULL;
		SDL_DestroyRenderer((*vis)->render);
		SDL_Quit();
		*vis = NULL;
	}
}

t_visual	*new_visual(void)
{
	t_visual	*vis;

	if (!(vis = (t_visual*)malloc(sizeof(t_visual))))
		return (NULL);
	vis->win = NULL;
	vis->surface = NULL;
	vis->render = NULL;
	vis->texture = NULL;
	vis->quit = 0;
	//vis->event = 0; не знаю как начальное значение для padding[56] выставить
	//вероятно так Uint8, 8 бит, зануляем его
	//нужно проверить
	ft_bzero((void*)&vis->e, 56);
	return (vis);
}

void		init_vis(t_lem *lem)
{
	if (!(lem->vis = new_visual()))
		ft_exit(&lem, MALLOC_FAILURE);
	if ((SDL_Init(SDL_INIT_VIDEO)) < 0)
		ft_exit(&lem, SDL_INIT_ERROR);
	else
	{
		lem->vis->win = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_RESIZABLE);
		if (!lem->vis->win)
			ft_exit(&lem, SDL_WIN_ERROR);
		else
			lem->vis->surface = SDL_GetWindowSurface(lem->vis->win);
		lem->vis->render = SDL_CreateRenderer(lem->vis->win, -1, \
		SDL_RENDERER_ACCELERATED);
//		if (lem->vis->render == NULL)
//			ft_exit(&lem, MALLOC_FAILURE);
	}
	SDL_FillRect(lem->vis->surface, NULL, SDL_MapRGB(lem->vis->surface->format,\
	0x00, 0x00, 0x00));
}
