/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/05 12:58:26 by pcredibl         ###   ########.fr       */
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

void	print_dijk(t_dijk *dijk)
{
	ft_printf("\n------------------------\n");
	ft_printf("|       DIJKSTRA        |\n");
	ft_printf("------------------------\n");
	ft_printf("|name        %10s|\n", dijk->vrx);
	ft_printf("|ancestor    %10s|\n", dijk->anc);
	ft_printf("|distantion  %10d|\n", dijk->dist);
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
		ft_printf("\n-----------------------\n");
		ft_printf("|name:  %14s|\n|x:     %14d|\n|y:     %14d|\n|type:  %14d|\
			\n|visit: %14d|\n", vrx->name, vrx->x, vrx->y, vrx->type, vrx->visit);
		if (vrx->adj)
		{
			ft_printf("|adj:   ");
			adj = vrx->adj;
			while (adj->next)
			{
				ft_printf("%s (w:%d, d:%d), ", adj->name, adj->weight, adj->dir);
				adj = adj->next;
			}
			ft_printf("%s (w:%d, d:%d)|\n", adj->name, adj->weight, adj->dir);
		}
		vrx = vrx->next;
	}
}

int		ft_char_count(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (*str++)
	{
		if (*str == c)
			++i;
	}
	return (i);
}

int		ft_len_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

void	del_adj(t_vrx *vrx, char *name)
{
	t_adj	*temp;
	t_adj	*temp2;

	temp = vrx->adj;
	if (!ft_strcmp(temp->name, name))
	{
		vrx->adj = temp->next;
		temp->next = NULL;
		free(temp);
	}
	else
	{
		while (temp && temp->next && ft_strcmp(name, temp->next->name))
			temp = temp->next;
		temp2 = temp->next;
		temp->next = temp->next ? temp->next->next : NULL;
		temp2 ? free(temp2) : 0;
	}
}
