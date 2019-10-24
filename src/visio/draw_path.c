/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:38:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/24 19:26:41 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_path(t_visual *vis, t_vrx *vrx, t_path *path, char color)
{
	//SDL_SetRenderDrawColor(vis->render, BLACK, 0);
	//SDL_RenderClear(vis->render);
	draw_edges(vis, vrx);
	while (path->next)
	{
		SDL_Delay(100);
		draw_edge(vis, path->vrx, path->next->vrx, color);
		draw_vertex(vis, path->vrx, color);
		draw_vertex(vis, path->next->vrx, color);
		path = path->next;
		SDL_RenderPresent(vis->render);
	}
	SDL_Delay(1000);
}
