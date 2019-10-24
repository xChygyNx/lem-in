/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:27:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/24 21:17:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_visual	*new_visual(void)
{
	t_visual	*vis;

	if (!(vis = (t_visual*)malloc(sizeof(t_visual))))
		return (NULL);
	vis->win = NULL;
	vis->surface = NULL;
	vis->render = NULL;
	vis->texture = NULL;
	vis->quit = 0;
	vis->run = 0;
	ft_bzero((void*)&vis->e, 56);
	return (vis);
}

void			initilize_visio(t_lem *lem)
{
	if (!(lem->vis = new_visual()))
		ft_exit(&lem, MALLOC_FAILURE);
	if ((SDL_Init(SDL_INIT_VIDEO)) < 0)
		ft_exit(&lem, SDL_INIT_ERROR);
	else if (TTF_Init() == -1)
		ft_exit(&lem, SDL_INIT_ERROR);
	else
	{
		lem->vis->win = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!lem->vis->win)
			ft_exit(&lem, SDL_WIN_ERROR);
		lem->vis->render = SDL_CreateRenderer(lem->vis->win, -1, \
		SDL_RENDERER_ACCELERATED);
		if (lem->vis->render == NULL)
			ft_exit(&lem, MALLOC_FAILURE);
		lem->vis->radius = ft_min(WIN_HEIGHT, WIN_WIDTH) / (lem->vert_c * 3);
		lem->vis->radius = ft_max(lem->vis->radius, 2);
		lem->vis->line_w = ft_max(lem->vis->radius / 3, 2);
		lem->vis->delay =  2500 * (1.0 / lem->edge_c);
	}
}

void		ft_free_visual(t_visual **vis)
{
	if (vis && *vis)
	{
		SDL_DestroyRenderer((*vis)->render);
		SDL_DestroyWindow((*vis)->win);
		(*vis)->win = NULL;
		SDL_Quit();
		*vis = NULL;
	}
}
