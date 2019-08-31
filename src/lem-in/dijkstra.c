/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:31:55 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/31 17:57:04 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_dijk		*dijk_lst(char *name)
{
	t_dijk			*lst;

	if (!(lst = (t_dijk*)malloc(sizeof(t_dijk))))
		return (NULL);
	if (!(lst->vrx = ft_strdup(name)))
	{
		free(lst);
		return (NULL);
	}
	lst->anc = NULL;
	lst->dist = MAX_INT;
	lst->next = NULL;
	return (lst);
}

static t_dijk		*new_dijk(t_lem *lem)
{
	t_dijk			*begin;
	t_dijk			*dijk;
	t_vrx			*temp_vrx;

	temp_vrx = lem->vrx;
	begin = dijk_lst(temp_vrx->name);
	dijk = begin;
	temp_vrx = temp_vrx->next;
	while (temp_vrx)
	{
		dijk->next = dijk_lst(temp_vrx->name);
		temp_vrx = temp_vrx->next;
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
	t_adj			*temp_adj;
	int				min_dist;

	while (!all_visit(lem->vrx))
	{
		temp_vrx = min_dist_vrx(lem->vrx, dijk, &min_dist);
		temp_vrx->visit = 1;
		temp_adj = temp_vrx->adj;
		while (temp_adj)
		{
			temp_dijk = find_dijk(temp_adj->name, dijk);
			if (temp_dijk->dist > min_dist + 1)
			{
				temp_dijk->dist = min_dist + 1;
				if (!(temp_dijk->anc = ft_strdup(temp_vrx->name)))
				{
					free_dijkstra(&dijk);
					return (NULL);
				}
			}
			temp_adj = temp_adj->next;
		}
	}
	return (dijk);
}

static char			*print_short_path(t_vrx *vrx, t_dijk *dijk)
{
	t_dijk		*temp_dijk;
	char		*path;

	if (!(path = ft_strnew(0)))
		return (NULL);
	while (vrx && vrx->type != END)
		vrx = vrx->next;
	temp_dijk = find_dijk(vrx->name, dijk);
	while (temp_dijk && temp_dijk->anc)
	{
		if (!(path = ft_strjoin_f(path, temp_dijk->vrx)))
			return (NULL);
		if (!(path = ft_strjoin_f(path, "|")))
			return (NULL);
		temp_dijk = find_dijk(temp_dijk->anc, dijk);
	}
	if (!(path = ft_strjoin_f(path, temp_dijk->vrx)))
			return (NULL);
	return (path);
}

char				*dijkstra(t_lem *lem)
{
	t_dijk			*dijk;
	char			*path;

	dijk = new_dijk(lem);
	dijk->dist = 0;
	if (!(dijk = dijkstra_algo(lem, dijk)))
		ft_exit(&lem, MALLOC_FAILURE);
	if (!(path = print_short_path(lem->vrx, dijk)))
		ft_exit(&lem, MALLOC_FAILURE);
	free_dijkstra(&dijk);
	return (path);
}
