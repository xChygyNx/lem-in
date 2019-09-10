/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/10 16:43:41 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	unvisit(t_vrx *vertex)
{
	while (vertex)
	{
		vertex->visit = 0;
		vertex = vertex->next;
	}
}

t_vrx	*get_vrx(t_vrx *vrx, char *name)
{
	while (vrx && ft_strcmp(name, vrx->name))
		vrx = vrx->next;
	return (vrx);
}

t_adj	*get_adj(t_adj *adj, char *name)
{
	while (adj && ft_strcmp(name, adj->name))
		adj = adj->next;
	return (adj);
}

t_bfs	*find_bfs(char *name, t_bfs *bfs)
{
	while (bfs && ft_strcmp(name, bfs->name))
		bfs = bfs->next;
	return (bfs ? bfs : NULL);
}

void	ft_print_lem_info(t_lem *lem)
{
	t_vrx		*vrx;
	t_adj		*adj;

	ft_printf("\n-----------------------\n");
	ft_printf("|ants:     %11d|\n", lem->ant_c);
	ft_printf("|vertexes: %11d|\n", lem->vert_c);
	ft_printf("|edges:    %11d|\n", lem->edge_c);
	vrx = lem->vrx;
	while (vrx)
	{
		ft_printf("-----------------------\n");
		ft_printf("|name:  {red}%14s{eoc}|\n|x:     %14d|\n|y:     %14d|\n\
|type:  %14d|\n|visit: %14d|\n|sep:   %14s|\n",\
		 vrx->name, vrx->x, vrx->y, vrx->type, vrx->visit,\
		 vrx->sep ? "YES" : "NO");
		if (vrx->adj)
		{
			ft_printf("|adj:   ");
			adj = vrx->adj;
			while (adj->next)
			{
				ft_printf("{green}%s{eoc} (w:%d, d:%d), ",\
				adj->name, adj->weight, adj->dir);
				adj = adj->next;
			}
			ft_printf("{green}%s{eoc} (w:%d, d:%d)|\n",\
			adj->name, adj->weight, adj->dir);
		}
		vrx = vrx->next;
	}
}
