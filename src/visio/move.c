/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:41:56 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/26 16:08:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*static void		draw_along_x(t_fdf *fdf, t_vector a, t_delta delta)
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
}*/

static void		paint_ants(t_visual *vis, t_ant *army, int meat)
{
	while (meat--)
	{
		filledCircleRGBA(vis->render, army->x, army->y, vis->radius / 4 > 1 ? vis->radius / 4 : 2, 255, 255, 255, 255);
		army = army->next;
	}
}

static void		set_ants_dislocation(t_ant *army, int meat)
{
	while (meat--)
	{
		army->x = army->path->vrx->x;
		army->y = army->path->vrx->y;
		army->dx = army->path->next->vrx->x - army->x;
		army->dy = army->path->next->vrx->y - army->y;
		army = army->next;
	}
}

static void		move_ants(t_ant *army, int meat)
{
	while(meat--)
	{
		army->x += army->dx / STEPS;
		army->y += army->dy / STEPS;
		army = army->next;
	}
}

void			draw_move_ants(t_lem *lem, t_ant *army, int meat)
{
	int		i;
	float	delay;

	set_ants_dislocation(army, meat);
	i = STEPS > 0 ? STEPS : 0;
	while (i--)
	{
		draw_graph(lem, NULL, 0);
		move_ants(army, meat);
		paint_ants(lem->vis, army, meat);
		delay = lem->vis->delay >= 0 ? lem->vis->delay / 25 : 1 / (-2 * (lem->vis->delay / 25));
		SDL_RenderPresent(lem->vis->render);
		SDL_Delay(lem->vis->delay);
	}

	/*t_delta delta;

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
	}*/
}


