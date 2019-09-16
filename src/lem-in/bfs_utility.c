/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:57:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/16 22:44:05 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bfs	*new_bfs(t_vrx *vrx)
{
	t_bfs	*bfs;

	if (!(bfs = (t_bfs*)malloc(sizeof(t_bfs))))
		return (NULL);
	bfs->vrx = vrx;
	bfs->anc = NULL;
	bfs->next = NULL;
	return (bfs);
}

t_bfs	*bfs_list(t_lem *lem)
{
	t_bfs	*begin;
	t_bfs	*temp;
	t_vrx	*vrx;

	vrx = lem->vrx;
	if (!(begin = new_bfs(lem->vrx)))
		ft_exit(&lem, MALLOC_FAILURE);
	temp = begin;
	vrx = vrx->next;
	while (vrx)
	{
		if (!(temp->next = new_bfs(vrx)))
		{
			free_bfs(&begin);
			ft_exit(&lem, MALLOC_FAILURE);
		}
		temp = temp->next;
		vrx = vrx->next;
	}
	return (begin);
}

void	free_bfs(t_bfs **bfs)
{
	t_bfs	*first;
	t_bfs	*second;

	if (bfs && *bfs)
	{
		first = *bfs;
		while (first)
		{
			second = first;
			first = first->next;
			second->vrx = NULL;
			free(second);
		}
		*bfs = NULL;
	}
}

void	add_anc(t_bfs *begin, char *name, char *anc)
{
	t_bfs	*bfs;

	bfs = get_bfs(begin, name);
	bfs->anc = get_bfs(begin, anc);
}
