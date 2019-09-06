/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:12:12 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/06 16:39:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		dfs(t_lem *lem, char *name)
{
	t_vrx *vrx_t;
	t_adj *adj_t;

	if (!(vrx_t = get_vrx(lem->vrx, name)))
		return (0);
	if (vrx_t->visit)
		return (0);
	if (vrx_t->type == END)
		return (1);
	vrx_t->visit = 1;
	adj_t = vrx_t->adj;
	while (adj_t)
	{
		if (dfs(lem, adj_t->name))
			return (1);
		adj_t = adj_t->next;
	}
	return (0);
}
