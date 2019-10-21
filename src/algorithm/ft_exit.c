/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:39:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/21 19:19:01 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			destroy_visual(t_lem *lem)
{
	SDL_DestroyRenderer(lem->vis->render);
    SDL_DestroyWindow(lem ->vis->win);

    SDL_Quit();
}

static void		usage(void)
{
	ft_fprintf(2, "USAGE:\n\t%-7s - print decision without input map\n\
	%-7s - turn on visualization\n", "[-wm]", "[-v]");
}

void			ft_exit(t_lem **lem, int err)
{
	ft_del_lem(lem);
	if (err == INVALID_INPUT)
		ft_fprintf(2, "Error: Invalid map\n");
	else if (err == START_END)
		ft_fprintf(2, "Error: Two starts/ends, or not start/end\n");
	else if (err == DOUBLE_VRX)
		ft_fprintf(2, "Error: Duplicate vertex or same coordinates\n");
	else if (err == ONE_COMPONENT)
		ft_fprintf(2, "Error: Start & end situated in different \
connected components\n");
	else if (err == SDL_INIT_ERROR)
		ft_fprintf(2, "SDL could not initialize! SDL_Error: %s\n", \
		SDL_GetError());
	else if (err == SDL_WIN_ERROR)
		ft_fprintf(2, "SDL could not create a window! SDL_Error: %s\n", \
		SDL_GetError());
	else if (err == USAGE)
		usage();
	else
		perror("Error: ");
	exit(err);
}
