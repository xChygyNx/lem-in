/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:04:10 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/26 16:19:14 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

SDL_Rect		get_rectangle(int width, int height, int x, int y)
{
	SDL_Rect		rectangle;

	rectangle.h = height;
	rectangle.w = width;
	rectangle.x = x;
	rectangle.y = y;
	return (rectangle);
}

SDL_Texture		*text2texture(SDL_Renderer *rend, TTF_Font *font,\
				char *str, t_color c)
{
	SDL_Color		color;
	SDL_Surface		*text_surface;
	SDL_Texture		*texture;

	color.a = c.t_rgb.alpha;
	color.b = c.t_rgb.blue;
	color.g = c.t_rgb.green;
	color.a = c.t_rgb.red;
	text_surface = TTF_RenderText_Solid(font, str, color);
	if (!text_surface)
		return (NULL);
	texture = SDL_CreateTextureFromSurface(rend, text_surface);
	if (!text_surface)
		return (NULL);
	SDL_FreeSurface(text_surface);
	return (texture);
}

void			texture2render(SDL_Renderer *rend, SDL_Texture *text,\
				SDL_Rect rect)
{
	SDL_RenderCopy(rend, text, NULL, &rect);
	SDL_RenderPresent(rend);
}

void			intro(t_lem *lem)
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
