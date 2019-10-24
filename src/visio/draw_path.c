/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:38:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/24 20:07:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_path(t_visual *vis, t_path *path, char color)
{
	SDL_SetRenderDrawColor(vis->render, BLACK, 0);
	while (path->next)
	{
		SDL_Delay(vis->delay);
		if(path->vrx->sep && path->next->vrx->sep)
			draw_edge(vis, path->vrx, path->next->vrx, 'r');
		else
			draw_edge(vis, path->vrx, path->next->vrx, color);
		draw_vertex(vis, path->vrx, color);
		draw_vertex(vis, path->next->vrx, color);
		path = path->next;
		SDL_RenderPresent(vis->render);
	}
	SDL_Delay(vis->delay * 3);
}
