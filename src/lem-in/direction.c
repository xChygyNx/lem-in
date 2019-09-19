/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:58:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/19 19:52:45 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	change_eds_wght(t_vrx *vrx_t, char *end, int weight)
{
	t_adj	*adj_t;

	if ((adj_t = get_adj(vrx_t->adj, end)))
		adj_t->weight = weight;
}

static void	separate_vrxs(t_path *path, char tumbler)
{
	path = path->next;
	while (path->next)
	{
		path->vrx->sep = tumbler;
		path = path->next;
	}
}

void		change_dir(t_vrx *vrx_t, char *end, char dir)
{
	t_adj	*adj_t;

	if ((adj_t = get_adj(vrx_t->adj, end)))
		adj_t->dir = dir;
}

void		redirect_lem(t_path *path, char tumb)
{
	t_path	*temp;

	temp = path;
	while (temp->next)
	{
		change_dir(temp->vrx, temp->next->vrx->name, tumb);
		change_eds_wght(temp->vrx, temp->next->vrx->name, !tumb ? 0 : 1);
		change_eds_wght(temp->next->vrx, temp->vrx->name, !tumb ? -1 : 1);
		temp = temp->next;
	}
	separate_vrxs(path, !tumb ? ON : OFF);
}
