/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/19 22:50:24 by astripeb         ###   ########.fr       */
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
