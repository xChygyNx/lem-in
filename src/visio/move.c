/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:41:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/25 15:53:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		draw_along_x(t_fdf *fdf, t_vector a, t_delta delta)
{
	int d;
	int x;
	int y;

	x = a.x;
	y = a.y;
	d = -delta.length_x;
	++delta.length;
	while (delta.length--)
	{
		pixel_put_to_str(fdf, x + fdf->view->off_x, y + fdf->view->off_y, a.c);
		x += delta.dx;
		d += 2 * delta.length_y;
		if (d > 0)
		{
			d -= 2 * delta.length_x;
			y += delta.dy;
		}
	}
}

static void		draw_along_y(t_fdf *fdf, t_vector a, t_delta delta)
{
	int d;
	int x;
	int y;

	x = a.x;
	y = a.y;
	d = -delta.length_y;
	++delta.length;
	while (delta.length--)
	{
		pixel_put_to_str(fdf, x + fdf->view->off_x, y + fdf->view->off_y, a.c);
		y += delta.dy;
		d += 2 * delta.length_x;
		if (d > 0)
		{
			d -= 2 * delta.length_y;
			x += delta.dx;
		}
	}
}

void			draw_line(t_visual *vis, t_vector a, t_vector b)
{
	t_delta delta;

	delta.dx = (b.x - a.x >= 0 ? 1 : -1);
	delta.dy = (b.y - a.y >= 0 ? 1 : -1);
	delta.length_x = abs(b.x - a.x);
	delta.length_y = abs(b.y - a.y);
	delta.length = delta.length_x > delta.length_y ?\
	delta.length_x : delta.length_y;
	if (delta.length == 0)
		pixel_put_to_str(fdf, a.x + fdf->view->off_x, a.y + fdf->view->off_y,\
		a.c);
	else
	{
		if (delta.length_y <= delta.length_x)
			draw_along_x(fdf, a, delta);
		else
			draw_along_y(fdf, a, delta);
	}
}
