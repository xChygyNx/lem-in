/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:13 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/23 23:35:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_vertex(t_visual *vis, t_vrx *vrx, char c)
{
	if (c == 'r')
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius, 255, 30, 30, 255);
	else if (c == 'b')
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius, 30, 30, 255, 255);
	else if (c == 'g' && !vrx->type)
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius, 30, 100, 30, 255);
	if (vrx->type == START)
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius - 3, 30, 255, 30, 255);
	else if (vrx->type == END)
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius - 3, 255, 255, 30, 255);
	else if (!vrx->type)
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius - 3, 30, 30, 100, 255);
}

void		draw_edge(t_visual *vis, t_vrx *from, t_vrx *to, char c)
{
	if (c == 'r')
	{
		thickLineRGBA(vis->render, from->x, from->y, to->x, to->y,\
		vis->line_w * 2, 255, 0, 0, 150);
	}
	else if (c == 'b')
	{
		thickLineRGBA(vis->render, from->x, from->y, to->x, to->y,\
		vis->line_w, 0, 0, 100, 255);
	}
	else
	{
		thickLineRGBA(vis->render, from->x, from->y, to->x, to->y,\
		vis->line_w * 2, 0, 150, 0, 150);
	}
}

static void draw_listpath(t_visual *vis, t_listpath *lp)
{
	t_path		*path;

	while (lp)
	{
		path = lp->path;
		while (path->next)
		{
			draw_edge(vis, path->vrx, path->next->vrx, 'r');
			draw_vertex(vis, path->vrx, 'r');
			path = path->next;
		}
		draw_vertex(vis, path->vrx, 'r');
		lp = lp->next;
	}
}

static void	draw_edges(t_visual *vis, t_vrx *vrx)
{
	t_adj		*adj;

	while (vrx)
	{
		adj = vrx->adj;
		while (adj)
		{
			draw_edge(vis, vrx, adj->vrx, 'b');
			adj = adj->next;
		}
		vrx = vrx->next;
	}
}

void		draw_graph(t_lem *lem, t_listpath *listpath)
{
	t_vrx	*vrx;

	SDL_SetRenderDrawColor(lem->vis->render, 0, 0, 0, 0);
	SDL_RenderClear(lem->vis->render);
	vrx = lem->vrx;
	draw_edges(lem->vis, vrx);
	while (vrx)
	{
		draw_vertex(lem->vis, vrx, 'b');
		vrx = vrx->next;
	}
	draw_listpath(lem->vis, listpath);
	SDL_RenderPresent(lem->vis->render);
	usleep(1000000);
}
