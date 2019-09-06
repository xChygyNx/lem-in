/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edges_to_lem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:48:04 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/06 17:36:38 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			double_hyphen(char *str)
{
	char		*begin;

	begin = str;
	while (*(++str))
		if (*str == '-' && *(str - 1) == '-')
			return (1);
	str = begin;
	return (0);
}

int					exist_vertex(t_vrx *vrx, char **vertexes)
{
	int			v1;
	int			v2;

	v1 = 0;
	v2 = 0;
	while ((!v1 || !v2) && vrx)
	{
		v1 += !ft_strcmp(vrx->name, vertexes[0]) ? 1 : 0;
		v2 += !ft_strcmp(vrx->name, vertexes[1]) ? 1 : 0;
		if (v1 && v2)
			break ;
		vrx = vrx->next;
	}
	if (!v1 || !v2)
		return (0);
	return (1);
}

void				ft_edge(t_lem *lem, int fd)
{
	char	**vertexes;

	lem->edge_c = 0;
	while (lem->line && lem->line[0])
	{
		if (lem->line[0] != '#')
		{
			if (!(vertexes = ft_strsplit(lem->line, '-')))
				ft_exit(&lem, MALLOC_FAILURE);
			if (ft_len_arr(vertexes) != 2 || double_hyphen(lem->line))
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
