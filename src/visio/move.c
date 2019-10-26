/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:41:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/26 11:42:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

typedef struct		s_delta
{
	int				dx;
	int				dy;
	int				dz;
	int				length_x;
	int				length_y;
	int				length_z;
	int				length;
}					t_delta;

static void		draw_along_x(t_visual *vis, int x, int y, t_delta delta)
{
	int d;

	d = -delta.length_x;
	++delta.length;
	while (delta.length--)
	{
		filledCircleRGBA(vis->render, x, y, vis->radius / 2, 100, 100, 100, 0);
		x += delta.dx;
		d += 2 * delta.length_y;
		if (d > 0)
		{
			d -= 2 * delta.length_x;
			y += delta.dy;
		}
	}
}

static void		draw_along_y(t_visual *vis, int x, int y, t_delta delta)
{
	int d;

	d = -delta.length_y;
	++delta.length;
	while (delta.length--)
	{
		filledCircleRGBA(vis->render, x, y, vis->radius / 2, 100, 100, 100, 0);
		y += delta.dy;
		d += 2 * delta.length_x;
		if (d > 0)
		{
			d -= 2 * delta.length_y;
			x += delta.dx;
		}
	}
}

void			draw_line(t_lem *lem, t_vrx *a, t_vrx *b)
{
	t_delta delta;

	delta.dx = (b->x - a->x >= 0 ? 1 : -1);
	delta.dy = (b->y - a->y >= 0 ? 1 : -1);
	delta.length_x = abs(b->x - a->x);
	delta.length_y = abs(b->y - a->y);
	delta.length = delta.length_x > delta.length_y ?\
	delta.length_x : delta.length_y;
	if (delta.length == 0)
		filledCircleRGBA(lem->vis->render, a->x, a->y, lem->vis->radius / 2, 100, 100, 100, 0);
	else
	{
		if (delta.length_y <= delta.length_x)
			draw_along_x(lem, a->x, a->y, delta);
		else
			draw_along_y(lem, a->x, a->y, delta);
	}
}
