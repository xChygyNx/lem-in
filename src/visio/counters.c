/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:12:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/29 15:57:07 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	counter_reserve(t_lem *lem, int fresh_meat)
{
	//static int	ant_c = lem->ant_c;
	char				*reserve_str;
	struct SDL_Rect		rect;
	t_color				c;
	struct SDL_Texture	*texture;

	lem->reserve = lem->reserve - fresh_meat > 0 ? lem->reserve - fresh_meat : 0;
	reserve_str = ft_itoa(lem->reserve);
	//reserve_str = ft_strjoin_s("Reserve: ", reserve_str);
	
	ft_printf("%s\n", reserve_str);
	free(reserve_str);
	rect = get_rectangle(100, 20, 10, 10);
	c.color = ~0;
	texture = text2texture(lem->vis->render, lem->vis->font, reserve_str, c);
	texture2render(lem->vis->render, texture, rect);
}

void	counter_heroes(t_lem *lem, t_ant *army, int meat)
{
	char				*heroes_str;
	struct SDL_Rect		rect;
	t_color				c;
	struct SDL_Texture	*texture;

	lem->heroes += almost_complete_mission(army, meat);
	heroes_str = ft_itoa(lem->heroes);
	heroes_str = ft_strjoin_s("Finish: ", heroes_str);
	free(heroes_str);
	rect = get_rectangle(100, 20, 10, 50);
	c.color = ~0;
	texture = text2texture(lem->vis->render, lem->vis->font, heroes_str, c);
	texture2render(lem->vis->render, texture, rect);
}