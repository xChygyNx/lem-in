/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:37:05 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/19 12:24:17 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "SDL.h"

# ifdef __linux__
	# define WIN_HEIGHT 480
	# define WIN_WIDTH 640
# else
	# define WIN_HEIGHT 1200
	# define WIN_WIDTH 1600
# endif

typedef struct		 		s_visual
{
	struct SDL_Window		*window;	//окно
	struct SDL_Surface		*surface;	//поверхность окна
	struct SDL_Renderer		*render;	//рендер (я так понял аналог изображения)
	union SDL_Event			event;		//событие
	char					quit;		//флаг выхода

}							t_visual;

t_visual			*init(void);

#endif
