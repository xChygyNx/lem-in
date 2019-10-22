/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:13 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/22 17:22:38 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "SDL2_gfxPrimitives.h"
static void draw_listpath(struct SDL_Renderer *rend, t_listpath *lp)
{
	t_path *path;

	while (lp)
	{
		path = lp->path;
		while (path->next)
		{
			thickLineRGBA(rend, path->vrx->x, path->vrx->y,\
			path->next->vrx->x, path->next->vrx->y,\
			8, 255, 0, 0, 150);
			path = path->next;
		}
		lp = lp->next;
	}
}

static void	draw_edges(struct SDL_Renderer *rend, t_vrx *vrx)
{
	t_adj *adj;

	while (vrx)
	{
		adj = vrx->adj;
		while (adj)
		{
			thickLineRGBA(rend, vrx->x, vrx->y, adj->vrx->x, adj->vrx->y,\
			4, 15, 109, 6, 255);
			adj = adj->next;
		}
		vrx = vrx->next;
	}
}

void		draw_graph(t_lem *lem)
{
	t_vrx *vrx;

	vrx = lem->vrx;
	draw_edges(lem->vis->render, vrx);
	draw_listpath(lem->vis->render, lem->listpath);
	while (vrx)
	{
		filledCircleRGBA(lem->vis->render, vrx->x, vrx->y,\
		15, 212, 165, 187, 0xFF);
		circleRGBA(lem->vis->render, vrx->x, vrx->y,\
		15, 109, 6, 255, 0xFF);
		vrx = vrx->next;
	}
}
