/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:38:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/25 21:54:32 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

/*
void		draw_move_ants(t_lem *lem, t_ant *army, int number)
{
	draw_graph(lem, lem->listpath);

}
*/
