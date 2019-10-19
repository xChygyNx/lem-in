/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:27:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/19 13:32:57 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_visual	*new_visual(void)
{
	t_visual	*vis;

	if (!(vis = (t_visual*)malloc(sizeof(t_visual))))
		return (NULL);
	vis->window = NULL;
	vis->surface = NULL;
	vis->render = NULL;
	//vis->event = 0; не знаю как начальное значение для padding[56] выставить
	vis->quit = 0;
	return (vis);
}

t_visual	*init(void)
{
	t_visual	*vis;

	if (!(vis = new_visual()))
		return (NULL);
	if ((SDL_Init(SDL_INIT_VIDEO)) < 0)
		ft_printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	else
	{
		vis->window = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_RESIZABLE);
		if (vis->window == NULL)
			ft_printf("SDL could not create a window! SDL_Error: %s\n", SDL_GetError());
		else
			//получаем поверхность окна
			vis->surface = SDL_GetWindowSurface(vis->window);
	}
	return (vis);
}
