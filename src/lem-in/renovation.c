/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renovation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:12:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/10 21:54:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_rev_dir(t_lem *lem, char *edge1, char *edge2)
{
	t_vrx	*vrx_t;
	t_adj	*adj_t;

	if ((vrx_t = get_vrx(lem->vrx, edge1)))
	{
		if ((adj_t = get_adj(vrx_t->adj, edge2)))
			return ((int)!adj_t->dir);
	}
	return (0);
}

void		renovate_rev_edge(t_lem *lem, char *edge1, char *edge2)
{
	t_vrx	*vrx_t;
	t_adj	*adj_t;

	if ((vrx_t = get_vrx(lem->vrx, edge1)))
	{
		if ((adj_t = get_adj(vrx_t->adj, edge2)))
		{
			adj_t->dir = ON;
			adj_t->weight = 1;
		}
	}
}

void		renovation_one_to_two_dir(t_lem *lem)
{
	t_vrx	*vrx_t;
	t_adj	*adj_t;

	vrx_t = lem->vrx;
	while (vrx_t)
	{
		vrx_t->sep = OFF;
		vrx_t->by_pos = OFF;
		adj_t = vrx_t->adj;
		while(adj_t)
		{
			if (!adj_t->dir && check_rev_dir(lem, adj_t->name, vrx_t->name))
				adj_t->weight = 0;
			else if (!adj_t->dir)
			{
				adj_t->dir = ON;
				adj_t->weight = 1;
				renovate_rev_edge(lem, adj_t->name, vrx_t->name);
			}
			adj_t = adj_t->next;
		}
		vrx_t = vrx_t->next;
	}
}

void		full_renovation_lem(t_lem *lem)
{
	t_vrx	*vrx_t;
	t_adj	*adj_t;

	vrx_t = lem->vrx;
	while (vrx_t)
	{
		vrx_t->sep = OFF;
		vrx_t->visit = OFF;
		adj_t = vrx_t->adj;
		while(adj_t)
		{
			adj_t->dir = ON;
			adj_t->weight = 1;
			adj_t = adj_t->next;
		}
		vrx_t = vrx_t->next;
	}
}

