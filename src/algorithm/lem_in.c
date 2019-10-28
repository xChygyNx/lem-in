/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aks <aks@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/28 23:02:15 by aks              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
t_color	get_color(int r, int g, int b, int a)
{
	t_color c;

	c.t_rgb.alpha = a;
	c.t_rgb.blue = b;
	c.t_rgb.green = g;
	c.t_rgb.red = r;
	return (c);
}

void	print_colors(void)
{
	ft_printf("#define A_MOCCASIN %u\n", get_color(255, 228, 181, 255).color);
	ft_printf("#define A_DARKTURQUOISE %u\n", get_color(0, 206, 209, 255).color);
	ft_printf("#define A_BLUE %u\n", get_color(0, 0, 255, 255).color);
	ft_printf("#define A_CYAN %u\n", get_color(0, 255, 255, 255).color);
	ft_printf("#define A_LAWNREEN %u\n", get_color(124, 252, 0, 255).color);
	ft_printf("#define A_DARJKHAKI %u\n", get_color(189, 183, 107, 255).color);
	ft_printf("#define A_YELLOW %u\n", get_color(255, 255, 0, 255).color);
	ft_printf("#define A_INDIANRED %u\n", get_color(205, 92, 92, 255).color);
	ft_printf("#define A_FIREBRICK %u\n", get_color(178, 34, 34, 255).color);
	ft_printf("#define A_DARKORANGE %u\n", get_color(255, 140, 0, 255).color);
	ft_printf("#define A_MAGENTA %u\n", get_color(255, 0, 255, 255).color);
	ft_printf("\n\n");
	ft_printf("#define V_START %u\n", get_color(30, 255, 30, 255).color);
	ft_printf("#define V_END %u\n", get_color(255, 0, 0, 255).color);
	ft_printf("#define V_RED %u\n", get_color(255, 0, 0, 255).color);
	ft_printf("#define V_BLUE %u\n", get_color(0, 0, 100, 255).color);
	ft_printf("#define V_GREEN %u\n", get_color(0, 150, 0, 255).color);
	ft_printf("#define V_YELLOW %u\n", get_color(255, 255, 0, 255).color);
	ft_printf("#define V_SIMPLE %u\n", get_color(30, 30, 100, 255).color);
	ft_printf("\n\n");
	ft_printf("#define E_BLUE %u\n", get_color(0, 0, 100, 255).color);
	ft_printf("#define E_RED %u\n", get_color(255, 0, 0, 150).color);
	ft_printf("#define E_GREEN %u\n", get_color(0, 150, 0, 150).color);
	ft_printf("#define E_YELLOW %u\n", get_color(255, 255, 0, 150).color);
}
*/

void			visual_mode(t_lem *lem, t_ant *army)
{
	initilize_visio(lem);
	draw_intro(lem);
	draw_graph(lem, NULL, 1);
	find_optimal_path(lem, army);
	lem->vis->delay = 250 / STEPS;
	offensive(lem, army);
	lem->visual ? draw_outro(lem) : 0;
}

int				main(int ac, char **av)
{
	t_lem	*lem;
	t_ant	*army;
//	int		fd;

//	fd = open("tests/test_from_smight", O_RDONLY);
//	print_colors();
	lem = create_lem(0);
	army = create_army(lem->ant_c);
	ac > 1 ? check_flags(av, lem) : 0;
	!lem->without_map ? ft_printf("%s\n", lem->map) : 0;
	if (lem->visual)
		visual_mode(lem, army);
	else
	{
		find_optimal_path(lem, army);
		offensive(lem, army);
	}
	ft_del_lem(&lem);
	return (0);
}
