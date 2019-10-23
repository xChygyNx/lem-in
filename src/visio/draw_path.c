/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:38:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/23 23:17:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_path(t_visual *vis, t_path *path, char color)
{
	while (path->next)
	{
		usleep(100000);
		draw_edge(vis, path->vrx, path->next->vrx, color);
		draw_vertex(vis, path->vrx, color);
		draw_vertex(vis, path->next->vrx, color);
		path = path->next;
		SDL_RenderPresent(vis->render);
	}
	usleep(1000000);
}
