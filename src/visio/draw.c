/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:13 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/22 22:44:19 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_vertex(struct SDL_Renderer *rend, t_vrx *vrx, char c)
{
	if (c == 'r')
	{
		filledCircleRGBA(rend, vrx->x, vrx->y, 15, 255, 50, 50, 255);
		filledCircleRGBA(rend, vrx->x, vrx->y, 13, 100, 0, 0, 255);
	}
	else if (c == 'b')
	{
		filledCircleRGBA(rend, vrx->x, vrx->y, 15, 50, 50, 255, 255);
		filledCircleRGBA(rend, vrx->x, vrx->y, 13, 0, 0, 100, 255);
	}
}

static void draw_listpath(struct SDL_Renderer *rend, t_listpath *lp)
{
	t_path *path;
	t_color		col;

	col.t_rgb.red = 255;
	col.t_rgb.blue = 0;
	col.t_rgb.green = 0;
	col.t_rgb.alpha = 150;
	while (lp)
	{
		path = lp->path;
		while (path->next)
		{
			thickLineColor(rend, path->vrx->x, path->vrx->y,\
			path->next->vrx->x, path->next->vrx->y, 8, col.color);
			draw_vertex(rend, path->vrx, 'r');
			path = path->next;
		}
		draw_vertex(rend, path->vrx, 'r');
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
	t_vrx *vrx;

	SDL_SetRenderDrawColor(lem->vis->render, 0, 0, 0, 0);
	SDL_RenderClear(lem->vis->render);
	vrx = lem->vrx;
	draw_edges(lem->vis->render, vrx);
	while (vrx)
	{
		draw_vertex(lem->vis->render, vrx, 'b');
		vrx = vrx->next;
	}
	draw_listpath(lem->vis->render, lem->listpath);
	SDL_RenderPresent(lem->vis->render);
}
