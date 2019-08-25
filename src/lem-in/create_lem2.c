/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:48:04 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/25 18:31:11 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			exist_vertex(t_rooms *room, char **vertexes)
{
	int			v1;
	int			v2;

	v1 = 0;
	v2 = 0;
	while ((!v1 || !v2) && room)
	{
		v1 += !ft_strcmp(room->name, vertexes[0]) ? 1 : 0;
		v2 += !ft_strcmp(room->name, vertexes[1]) ? 1 : 0;
		if (v1 && v2)
			break ;
		room = room->next;
	}
	if (!v1 || !v2)
		return (0);
	return (1);
}

static void			add_adj(t_lem *lem, char **v)
{
	int			i;
	int			n;
	t_rooms		*room;

	room = lem->rooms;
	if (!exist_vertex(room, v))
		ft_exit(&lem, INVALID_INPUT);
	i = 0;
	while (i < 2)
	{
		if (!ft_strcmp(room->name, v[0]) || !ft_strcmp(room->name, v[1]))
		{
			i++;
			n = !ft_strcmp(room->name, v[0]) ? 1 : 0;
			if (!(room->adj = ft_addlst(room->adj, v[n])))
				ft_exit(&lem, MALLOC_FAILURE);
		}
		room = room->next;
	}
	ft_free_arr(v);
	lem->edge_c += 1;
}

void				ft_edge(t_lem *lem, int fd)
{
	char	**vertexes;

	lem->edge_c = 0;
	while (lem->line)
	{
		if (lem->line[0] != '#')
		{
			if (!(vertexes = ft_strsplit(lem->line, '-')))
				ft_exit(&lem, MALLOC_FAILURE);
			if (ft_len_arr(vertexes) != 2)
			{
				ft_free_arr(vertexes);
				ft_exit(&lem, INVALID_INPUT);
			}
			add_adj(lem, vertexes);
		}
		free(lem->line);
		if (get_next_line(fd, &lem->line) < 1)
			break ;
		if (!(lem->map = ft_strjoin_f(lem->map, "\n"))\
		|| !(lem->map = ft_strjoin_f(lem->map, lem->line)))
			ft_exit(&lem, MALLOC_FAILURE);
	}
	lem->line = NULL;
}
