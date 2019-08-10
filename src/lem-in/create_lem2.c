/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:48:04 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/10 16:16:30 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	add_adj(t_rooms *lem, char **v)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if (!ft_strcmp(lem->name, v[0]) || !ft_strcmp(lem->name, v[1]))
		{
			!ft_strcmp(lem->name, v[0]) ? 
		}
	}
}

void		ft_edge(t_rooms *lem, char **line)
{
	char	**vertexes;

	lem += 0;
	while (*line)
	{
		if (*line[0] != '#')
		{
			vertexes = ft_strsplit(*line, '-');
			size_arr(vertexes);
			exist_vertex(vertexes, lem);
			add_adj(lem, vertexes);
		}
		get_next_line(0, line);
	}
}