/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:54:09 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/07 17:27:20 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bfs		*bfs_algo(t_lem *lem, t_queue *queue, t_bfs *bfs)
{
	t_vrx			*temp_vrx;
	t_vrx			*temp2_vrx;
	t_adj			*temp_adj;
	char			prev_w;

	prev_w = 1;
	while (queue)
	{
		temp_vrx = get_vrx(lem->vrx, queue->name);
		if (temp_vrx->type == END)
			break ;
		temp_adj = temp_vrx->adj;
		while (temp_adj)
		{
			if (!temp_adj->dir)
				continue ;
			if (prev_w == -1 && temp_vrx->sep && temp_adj->weight > 0)
				continue ;
			temp2_vrx = get_vrx(lem->vrx, temp_adj->name);
			queue = !temp2_vrx->visit ? add_qu(queue, temp_adj->name) : queue;
			bfs = !temp2_vrx->visit ? add_bfs(temp_adj->name, temp_vrx->name, bfs, lem) : bfs;
			temp2_vrx->visit = 1;
			temp_adj = temp_adj->next;
		}
		del_elem_qu(&queue);
		}
	free_qu(queue);
	return (bfs);
}

static char			*shortest_path(t_vrx *vrx, t_bfs *bfs)
{
	t_bfs		*temp_bfs;
	char		*path;

	if (!(path = ft_strnew(0)))
		return (NULL);
	while (vrx && vrx->type != END)
		vrx = vrx->next;
	temp_bfs = find_bfs(vrx->name, bfs);
	while (temp_bfs && temp_bfs->anc)
	{
		if (!(path = ft_strjoin_f(path, temp_bfs->name)))
			return (NULL);
		if (!(path = ft_strjoin_f(path, "|")))
			return (NULL);
		temp_bfs = find_bfs(temp_bfs->anc, bfs);
	}
	if (!(path = ft_strjoin_f(path, temp_bfs->name)))
			return (NULL);
	return (path);
}

char				*bfs(t_lem *lem, t_bfs **bfs_src)
{
	char			*path;
	t_bfs			*bfs;
	t_queue			*queue;

	bfs = *bfs_src ? *bfs_src : new_bfs(lem);
	queue = new_queue(lem);
	bfs = bfs_algo(lem, queue, bfs);
	//if (!(path = print_short_path(lem->vrx, bfs)))
		//ft_exit(&lem, MALLOC_FAILURE);
	path = shortest_path(lem->vrx, bfs);
	//free_bfs(bfs);
	return (path);
}
