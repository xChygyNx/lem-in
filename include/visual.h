/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:37:05 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/28 15:13:19 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <SDL.h>
# include <SDL2_gfxPrimitives.h>
# include <SDL_ttf.h>
# include <math.h>

# ifdef __linux__
	# define WIN_HEIGHT 800
	# define WIN_WIDTH 1000
	# define INDENT 100
# else
	# define WIN_HEIGHT 1200
	# define WIN_WIDTH 1600
	# define INDENT 100
# endif

# define START_COLOR 30, 255, 30
# define END_COLOR 255, 0, 0
# define SIMPLE_VRX 30, 30, 100
# define RED_LINE 255, 0, 0
# define GREEN_LINE 0, 150, 0
# define BLUE_LINE 0, 0, 100
# define BLACK 0, 0, 0
# define YELLOW 255, 255, 0

# define U_RED 255
# define U_BLUE 16711680
# define U_GOLD 55295
# define U_PURPLE 8388736
# define U_BROWN 1262987
# define U_GREEN 25600
# define U_ORANGE 17916
# define U_AQUA 16776960
# define U_INDIGO 8519755
# define U_PINK 13353215
# define U_WHITE 16777215


# define STEPS	100

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
	struct _TTF_Font		*font; 		//шрифт для заставок
	char					quit;		//флаг выхода
	char					run;		//флаг запуска визуализации
	int						radius;		//радиус вершин
	int						line_w;		//толщина линий
	int						delay;		//скорость воспроизведения
}							t_visual;

void		ft_free_visual(t_visual **vis);

#endif
