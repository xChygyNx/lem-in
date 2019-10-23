/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:13 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/23 19:37:19 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_vertex(struct SDL_Renderer *rend, int radius, t_vrx *vrx, char c)
{
	if (c == 'r')
		filledCircleRGBA(rend, vrx->x, vrx->y, radius, 255, 30, 30, 255);
	else if (c == 'b')
		filledCircleRGBA(rend, vrx->x, vrx->y, radius, 30, 30, 255, 255);
	if (vrx->type == START)
		filledCircleRGBA(rend, vrx->x, vrx->y, radius - 3, 30, 255, 30, 255);
	else if (vrx->type == END)
		filledCircleRGBA(rend, vrx->x, vrx->y, radius - 3, 255, 255, 30, 255);
	else if (c == 'r' && !vrx->type)
		filledCircleRGBA(rend, vrx->x, vrx->y, radius - 3, 30, 30, 100, 255);
	//else if (c == 'b' && !vrx->type)
		//filledCircleRGBA(rend, vrx->x, vrx->y, radius - 3, 0, 0, 100, 255);
}

static void draw_listpath(int rc, struct SDL_Renderer *rend, t_listpath *lp)
{
	t_path		*path;
	t_color		col;
	int			radius;

	col.t_rgb.red = 255;
	col.t_rgb.blue = 0;
	col.t_rgb.green = 0;
	col.t_rgb.alpha = 150;
	//radius = rc * 5;
	radius = rc ? ft_min(WIN_HEIGHT, WIN_WIDTH) / (rc * 3) : 1;
	while (lp)
	{
		path = lp->path;
		while (path->next)
		{
			thickLineColor(rend, path->vrx->x, path->vrx->y,\
			path->next->vrx->x, path->next->vrx->y, 8, col.color);
			draw_vertex(rend, radius, path->vrx, 'r');
			path = path->next;
		}
		draw_vertex(rend, radius, path->vrx, 'r');
		lp = lp->next;
	}
}

static void	draw_edges(struct SDL_Renderer *rend, t_vrx *vrx)
{
	t_adj		*adj;

	while (vrx)
	{
		adj = vrx->adj;
		while (adj)
		{
			thickLineRGBA(rend, vrx->x, vrx->y, adj->vrx->x, adj->vrx->y,\
			4, 0, 0, 100, 255);
			adj = adj->next;
		}
		vrx = vrx->next;
	}
}

void		draw_graph(t_lem *lem)
{
	t_vrx	*vrx;
	int		room_count;
	int		radius;

	SDL_SetRenderDrawColor(lem->vis->render, 0, 0, 0, 0);
	SDL_RenderClear(lem->vis->render);
	vrx = lem->vrx;
	draw_edges(lem->vis->render, vrx);
	room_count = rooms_count(lem);
//	ft_printf("rooms count = %d\n", rooms_count);
	radius = room_count ? ft_min(WIN_HEIGHT, WIN_WIDTH) / (room_count * 3) : 1;
	while (vrx)
	{
		draw_vertex(lem->vis->render, room_count, vrx, 'b');
		vrx = vrx->next;
	}
	SDL_RenderPresent(lem->vis->render);
	draw_listpath(room_count, lem->vis->render, lem->listpath);
	SDL_RenderPresent(lem->vis->render);
}
