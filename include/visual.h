/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:37:05 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/22 22:00:44 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# ifdef __linux__
	# include "SDL.h"
	# include "SDL2_gfxPrimitives.h"
	# define WIN_HEIGHT 800
	# define WIN_WIDTH 1000
	# define INDENT 100
# else
	# include "/Users/pcredibl/Library/Frameworks/SDL2.framework/Headers/SDL.h"
	# define WIN_HEIGHT 1200
	# define WIN_WIDTH 1600
	# define INTEND 100
# endif

typedef union		u_color
{
	struct			s_rgb
	{
		unsigned char	red:8;
		unsigned char	green:8;
		unsigned char	blue:8;
		unsigned char	alpha:8;
	}				t_rgb;
	unsigned int	color;
}					t_color;

typedef struct		 		s_visual
{
	struct SDL_Window		*win;		// window окно
	struct SDL_Surface		*surface;	// поверхность окна
	struct SDL_Renderer		*render;	// изображение
	struct SDL_Texture		*texture;	// для теста
	union SDL_Event			e;			//event
	char					quit;		//флаг выхода
}							t_visual;

void		ft_free_visual(t_visual **vis);

#endif
