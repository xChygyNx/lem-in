/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:13 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/28 16:36:51 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_vertex(t_visual *vis, t_vrx *vrx, char c)
{
	if (c == 'r')
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius, RED_LINE, 255);
	else if (c == 'b')
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius, BLUE_LINE, 255);
	else if (c == 'g')
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius, GREEN_LINE, 255);
	else if (c == 'y')
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius, YELLOW, 255);
	if (vrx->type == START)
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius - 3, START_COLOR, 255);
	else if (vrx->type == END)
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius - 3, END_COLOR, 255);
	else if (!vrx->type)
		filledCircleRGBA(vis->render, vrx->x, vrx->y, vis->radius - 3, SIMPLE_VRX, 255);
}

void		draw_edge(t_visual *vis, t_vrx *from, t_vrx *to, char c)
{
	if (c == 'r')
	{
		thickLineRGBA(vis->render, from->x, from->y, to->x, to->y,\
		vis->line_w * 2, RED_LINE, 150);
	}
	else if (c == 'b')
	{
		thickLineRGBA(vis->render, from->x, from->y, to->x, to->y,\
		vis->line_w, BLUE_LINE, 255);
	}
	else if (c == 'g')
	{
		thickLineRGBA(vis->render, from->x, from->y, to->x, to->y,\
		vis->line_w * 2, GREEN_LINE, 150);
	}
	else
	{
		thickLineRGBA(vis->render, from->x, from->y, to->x, to->y,\
		vis->line_w * 2, YELLOW, 150);
	}
}

void		draw_edges(t_visual *vis, t_vrx *vrx)
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

void		draw_listpath(t_visual *vis, t_listpath *lp)
{
	t_path		*path;

	while (lp)
	{
		path = lp->path;
		while (path->next)
		{
			draw_edge(vis, path->vrx, path->next->vrx, 'g');
			draw_vertex(vis, path->vrx, 'g');
			path = path->next;
		}
		draw_vertex(vis, path->vrx, 'g');
		lp = lp->next;
	}
}

void		draw_path(t_visual *vis, t_path *path, char color)
{
	while (path->next)
	{
		event(vis);
		if (!vis->quit)
			return ;
		if(path->vrx->sep && path->next->vrx->sep)
			draw_edge(vis, path->vrx, path->next->vrx, 'r');
		else
			draw_edge(vis, path->vrx, path->next->vrx, color);
		SDL_Delay(vis->delay);
		draw_vertex(vis, path->vrx, color);
		draw_vertex(vis, path->next->vrx, color);
		path = path->next;
		SDL_RenderPresent(vis->render);
	}
	SDL_Delay(vis->delay * 3);
}
