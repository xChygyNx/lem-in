/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adj_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 18:48:05 by astripeb          #+#    #+#             */
/*   Updated: 2019/08/30 19:20:51 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_adj(t_lem *lem, char **v)
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
			if (!(vrx->adj = ft_addlst(vrx->adj, v[n], 1)))
				ft_exit(&lem, MALLOC_FAILURE);
		}
		vrx = vrx->next;
	}
	ft_free_arr(v);
	lem->edge_c += 1;
}

t_adj	*ft_addlst(t_adj *adj, char *elem, char weight)
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
	}
	else
	{
		if (!(begin = (t_adj*)malloc(sizeof(t_adj))))
			return (NULL);
		adj = begin;
		adj->name = NULL;
	}
	if (!(adj->name = ft_strdup(elem)))
		return (NULL);
	adj->next = NULL;
	adj->weight = weight;
	adj->dir = ON;
	return (begin);
}

void		change_dir(t_lem *lem, char *start, char *end)
{
	t_vrx	*t_vrx;
	t_adj	*t_adj;

	t_vrx = lem->vrx;
	while (t_vrx && ft_strcmp(start, t_vrx->name))
		t_vrx = t_vrx->next;
	t_adj = t_vrx ? t_vrx->adj : NULL;
	while (t_adj && ft_strcmp(end, t_adj->name))
		t_adj = t_adj->next;
	t_adj ? t_adj->dir = OFF : 0;
}
