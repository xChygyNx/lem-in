/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:31:55 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/31 15:59:44 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_dijk		*dijk_lst(char *s)
{
	t_dijk			*lst;

	lst = (t_dijk*)malloc(sizeof(t_dijk));
	lst->vrx = ft_strdup(s);
	lst->anc = NULL;
	lst->dist = MAX_INT;
	lst->next = NULL;
	return (lst);
}

static t_dijk		*new_dijk(t_lem *lem)
{
	t_dijk			*begin;
	t_dijk			*dijk;
	t_vrx			*temp;

	temp = lem->vrx;
	begin = dijk_lst(temp->name);
	dijk = begin;
	temp = temp->next;
	while (temp)
	{
		dijk->next = dijk_lst(temp->name);
		temp = temp->next;
		dijk = dijk->next;
	}
	return (begin);
}

static t_vrx		*min_dist_vrx(t_vrx *vrx, t_dijk *dijk, int *d)
{
	int				min_dist;
	int				distance;
	t_vrx			*temp_vrx;
	t_vrx			*min_dist_vrx;

	min_dist = MAX_INT;
	temp_vrx = vrx;
	while (temp_vrx)
	{
		distance = dist_vrx(temp_vrx->name, dijk);
		if (!temp_vrx->visit && min_dist >= distance)
		{
			min_dist = distance;
			min_dist_vrx = temp_vrx;
		}
		temp_vrx = temp_vrx->next;
	}
	*d = min_dist;
	return (min_dist_vrx);
}

static t_dijk		*dijkstra_algo(t_lem *lem, t_dijk *dijk)
{
	t_vrx			*temp_vrx;
	t_dijk			*temp_dijk;
	int				min_dist;

	while (!all_visit(lem->vrx))
	{
		temp_vrx = min_dist_vrx(lem->vrx, dijk, &min_dist);
		temp_vrx->visit = 1;
		while (temp_vrx->adj)
		{
			temp_dijk = find_dijk(temp_vrx->adj->name, dijk);
			if (temp_dijk->dist > min_dist + 1)
			{
				temp_dijk->dist = min_dist + 1;
				temp_dijk->anc = temp_vrx->name;
			}
			temp_vrx->adj = temp_vrx->adj->next;
		}
	}
	return (dijk);
}

void				dijkstra(t_lem *lem)
{
	t_dijk			*dijk;

	dijk = new_dijk(lem);
	dijk->dist = 0;
	dijk = dijkstra_algo(lem, dijk);
	while (dijk)
	{
		print_dijk(dijk);
		dijk = dijk->next;
	}
}
