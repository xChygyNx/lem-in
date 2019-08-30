/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_edges_to_lem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:48:04 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/30 16:46:06 by pcredibl         ###   ########.fr       */
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

static int			exist_vertex(t_vrx *vrx, char **vertexes)
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

static void			add_adj(t_lem *lem, char **v)
{
	int			i;
	int			n;
	t_vrx		*vrx;

	vrx = lem->vrx;
	if (!exist_vertex(vrx, v))
		ft_exit(&lem, INVALID_INPUT);
	i = 0;
	while (i < 2 && vrx)
	{
		if (!ft_strcmp(vrx->name, v[0]) || !ft_strcmp(vrx->name, v[1]))
		{
			i++;
			n = !ft_strcmp(vrx->name, v[0]) ? 1 : 0;
			//vrx->adj = vrx->adj ? vrx->adj : (t_adj*)malloc(sizeof(t_adj)); 
			if (!(vrx->adj = ft_addlst(vrx->adj, v[n], 1)))
				ft_exit(&lem, MALLOC_FAILURE);
		}
		vrx = vrx->next;
	}
	//ft_printf("vertex name = %s\n", vrx->name);
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
