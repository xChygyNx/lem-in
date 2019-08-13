/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:48:04 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/13 17:19:37 by pcredibl         ###   ########.fr       */
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
			//ft_printf("name = %s, v0 = %s, v1 = %s\n", lem->name, v[0], v[1]);
			i++;
			lem->adj = !ft_strcmp(lem->name, v[0]) ?\
			ft_addlst(lem->adj, v[1]) : ft_addlst(lem->adj, v[0]);
			//ft_printf("adj = %p, adj = %s\n", lem->adj, lem->adj);
		}
		lem = lem->next;
	}
}

void		ft_edge(t_rooms *lem, char **line, int fd)
{
	char	**vertexes;

	lem += 0;
	while (*line[0] && *line)
	{
		//ft_printf("I'm here\n");
		if (*line[0] != '#')
		{
			//ft_printf("line = %s,     %p\n", *line, *line);
			vertexes = ft_strsplit(*line, '-');
			is_two_vert(vertexes);
			exist_vertex(vertexes, lem);
			//ft_printf("I'm here\n");
			add_adj(lem, vertexes);
		}
		get_next_line(fd, line);
	}
}