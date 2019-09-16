/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:58:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/16 18:47:58 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	change_eds_wght(t_lem *lem, t_vrx *vrx_t, char *end, int weight)
{
	t_adj	*adj_t;

	if ((adj_t = get_adj(vrx_t->adj, end)))
		adj_t->weight = weight;
}

static void	separate_vrxs(t_lem *lem, t_path *path, char tumbler)
{
	path = path->next;
	while (path->next)
	{
		path->vrx->sep = tumbler;
		path = path->next;
	}
}

void		change_dir(t_lem *lem, t_vrx *vrx_t, char *end, char dir)
{
	t_adj	*adj_t;

	if ((adj_t = get_adj(vrx_t->adj, end)))
		adj_t->dir = dir;
}

void		redirect_lem(t_lem *lem, t_path *path, char tumbler)
{
	int		i;
	t_path	*temp;

	temp = path->next;
	while (temp->next)
	{
		change_dir(lem, temp->vrx, temp->next->vrx->name, tumbler);
		change_eds_wght(lem, temp->vrx, temp->next->vrx->name, !tumbler ? OFF : ON);
		change_eds_wght(lem, temp->next->vrx, temp->vrx->name, !tumbler ? -1 : 1);
		--i;
		temp = temp->next;
	}
	separate_vrxs(lem, path, !tumbler ? ON : OFF);
}
