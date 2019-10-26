/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:38:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/26 17:14:12 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		draw_graph(t_lem *lem, t_listpath *listpath, char f)
{
	t_vrx	*vrx;

	event(lem->vis);
	lem->visual = lem->vis->quit;
	if (!lem->visual)
		return ;
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
	f ? SDL_RenderPresent(lem->vis->render) : 0;
	SDL_Delay(lem->vis->delay * 3);
}

void			draw_intro(t_lem *lem)
{
	t_color		c;
	SDL_Texture *press;
	SDL_Rect	welcome;
	SDL_Rect	start;

	c.color = ~0;
	lem->vis->texture = text2texture(lem->vis->render, lem->vis->font, "Welcome to Lem-in", c);
	if (!lem->vis->texture)
		ft_exit(&lem, 0);
	press = text2texture(lem->vis->render, lem->vis->font, "Press F to start", c);
	if (!press)
		ft_exit(&lem, 0);
	welcome = get_rectangle(WIN_WIDTH / 2, INDENT, WIN_WIDTH / 4, WIN_HEIGHT / 2 - INDENT / 2);
	start = get_rectangle(300, 50, WIN_WIDTH / 2 - 150, WIN_HEIGHT / 2 + INDENT * 2);
	while(lem->vis->quit)
	{
		SDL_SetRenderDrawColor(lem->vis->render, 0, 0, 0, 0);
		SDL_RenderClear(lem->vis->render);
		texture2render(lem->vis->render, lem->vis->texture, welcome);
		SDL_Delay(500);
		texture2render(lem->vis->render, press, start);
		SDL_Delay(500);
		event(lem->vis);
	}
	SDL_DestroyTexture(lem->vis->texture);
	lem->vis->texture = NULL;
	SDL_DestroyTexture(press);
	lem->vis->quit = 1;
}
