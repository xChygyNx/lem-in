/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:38:33 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/31 17:55:10 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_dijk	*find_dijk(char *name, t_dijk *dijk)
{
	t_dijk	*temp;

	temp = dijk;
	while (ft_strcmp(name, temp->vrx))
		temp = temp->next;
	return (temp);
}

int		dist_vrx(char *name, t_dijk *dijk)
{
	t_dijk	*temp;

	temp = find_dijk(name, dijk);
	return (temp->dist);
}

int		all_visit(t_vrx *vrx)
{
	t_vrx	*begin;

	begin = vrx;
	while (vrx)
	{
		if (vrx->visit == 0)
		{
			vrx = begin;
			return (0);
		}
		vrx = vrx->next;
	}
	vrx = begin;
	return (1);
}

void	free_dijkstra(t_dijk **dijk)
{
	t_dijk		*first;
	t_dijk		*second;

	if (dijk)
	{
		first = *dijk;
		while (first)
		{
			second = first;
			first = first->next;
			second->vrx ? free(second->vrx) : 0;
			second->anc ? free(second->anc) : 0;
			free(second);
		}
		dijk = NULL;
	}
}
