/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:37:05 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/22 14:33:28 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "/Users/pcredibl/Library/Frameworks/SDL2.framework/Headers/SDL.h"

typedef struct		 		s_visual
{
	struct SDL_Window		*win;		// window окно
	struct SDL_Surface		*surface;	// поверхность окна
	struct SDL_Renderer		*render;	// изображение
	struct SDL_Texture		*texture;	// для теста
	union SDL_Event			e;			//event
	char					quit;		//флаг выхода
}							t_visual;

# ifdef __linux__
	# define WIN_HEIGHT 480
	# define WIN_WIDTH 640
# else
	# define WIN_HEIGHT 1200
	# define WIN_WIDTH 1600
# endif

void		ft_free_visual(t_visual **vis);

#endif
