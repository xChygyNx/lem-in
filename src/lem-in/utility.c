/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/27 23:30:26 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adj	*ft_addlst(t_adj *adj, char *elem)
{
	t_adj	*begin;

	if (adj)
	{
		begin = adj;
		while (adj->next)
			adj = adj->next;
		if (!(adj->next = (t_adj*)malloc(sizeof(t_adj))))
			return (NULL);
		adj = adj->next;
		if (!(adj->name = ft_strdup(elem)))
		{
			free(adj);
			return (NULL);
		}
		adj->next = NULL;
	}
	else
	{
		if (!(begin = (t_adj*)malloc(sizeof(t_adj))))
			return (NULL);
		begin->name = ft_strdup(elem);
		begin->next = NULL;
	}
	return (begin);
}

void	unvisit(t_vrx *vertex)
{
	while (vertex)
	{
		vertex->visit = 0;
		vertex = vertex->next;
	}
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
		ft_printf("|name:  %14s|\n|x:     %14d|\n|y:     %14d|\n|type:  \
%14d|\n|visit: %14d|\n", vrx->name, vrx->x, vrx->y, vrx->type, vrx->visit);
		if (vrx->adj)
		{
			ft_printf("|adj:   ");
			adj = vrx->adj;
			while (adj->next)
			{
				ft_printf("%s, ", adj->name);
				adj = adj->next;
			}
			ft_printf("%s|\n", adj->name);
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
