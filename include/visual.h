/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:37:05 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/24 20:05:29 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "SDL.h"
# include "SDL2_gfxPrimitives.h"
# include "SDL_ttf.h"
# include <math.h>

# ifdef __linux__
	# define WIN_HEIGHT 600
	# define WIN_WIDTH 800
	# define INDENT 50
# else
	# define WIN_HEIGHT 1200
	# define WIN_WIDTH 1600
	# define INDENT 100
# endif

# define START_COLOR 30, 255, 30
# define END_COLOR 255, 255, 30
# define SIMPLE_VRX 30, 30, 100
# define RED_LINE 255, 0, 0
# define GREEN_LINE 0, 150, 0
# define BLUE_LINE 0, 0, 100
# define BLACK 0, 0, 0

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
	char					run;		//флаг запуска визуализации
	int						radius;		//радиус вершин
	int						line_w;		//толщина линий
	int						delay;		//скорость воспроизведения
}							t_visual;

void		ft_free_visual(t_visual **vis);

#endif
