/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:57:21 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/07 15:07:31 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bfs	*add_bfs(char *name, char *anc, t_bfs *bfs, t_lem *lem)
{
	t_bfs	*temp;
	t_bfs	*start;

	start = bfs;
	while (bfs->next)
		bfs = bfs->next;
	if (!(temp = (t_bfs*)malloc(sizeof(t_bfs))))
		ft_exit(&lem, MALLOC_FAILURE);
	if (!(temp->name = ft_strdup(name)) || !(temp->anc = ft_strdup(anc)))
	{
		temp->name ? free(temp->name) : 0;
		free(bfs);
		ft_exit(&lem, MALLOC_FAILURE);
	}
	temp->next = NULL;
	bfs->next = temp;
	return (start);
}

t_bfs	*new_bfs(t_lem *lem)
{
	t_bfs	*begin;
	t_bfs	*bfs;
	t_vrx	*temp_vrx;

	temp_vrx = lem->vrx;
	if (!(bfs = (t_bfs*)malloc(sizeof(t_bfs))))
		ft_exit(&lem, MALLOC_FAILURE);
	if (!(bfs->name = ft_strdup(temp_vrx->name)))
	{
		free(bfs);
		bfs = NULL;
		ft_exit(&lem, MALLOC_FAILURE);
	}
	bfs->anc = NULL;
	bfs->next = NULL;
	return (bfs);
}

void	free_bfs(t_bfs *bfs)
{
	t_bfs	*temp;

	temp = bfs;
	while (temp)
	{
		temp = temp->next;
		free(bfs->name);
		free(bfs->anc);
		bfs->name = NULL;
		bfs->anc = NULL;
		free(bfs);
		bfs = temp;
	}
}
