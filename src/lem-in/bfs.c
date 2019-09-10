/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:54:09 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/10 19:40:09 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bfs		*bfs_algo(t_lem *lem, t_queue *queue, t_bfs *bfs)
{
	t_vrx			*vrx_s; //start vrx
	t_vrx			*vrx_e; //end vrx
	t_adj			*adj_t;
	//t_vrx			*vrx_t; //temp vrx
	//char			prev_w; //previous weight

	//prev_w = 1;
	while (queue)
	{
		vrx_s = get_vrx(lem->vrx, queue->name);
		if (vrx_s->type == END)
			break ;
		adj_t = vrx_s->adj;
		while (adj_t)
		{
			if (!adj_t->dir)
			{
				adj_t = adj_t->next;
				continue ;
			}
			//тут нужно перестроить логику
			//vrx_t = get_vrx(lem->vrx, )
			vrx_e = get_vrx(lem->vrx, adj_t->name);
			if (adj_t->weight > 0 && vrx_e->sep)
				vrx_e->by_pos = ON;
			if (!vrx_e->visit)
			{
				if (!vrx_s->by_pos || adj_t->weight < 0)
				{
					add_queue(&queue, adj_t->name, adj_t->weight);
					bfs = add_bfs(adj_t->name, vrx_s->name, bfs, lem);
					vrx_e->visit = 1;
				}
			}
			adj_t = adj_t->next;
		}
		vrx_s->by_pos = OFF;
		del_one_queue(&queue);
	}
	free_queue(&queue);
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
	if (!temp_bfs || !(path = ft_strjoin_f(path, temp_bfs->name)))
			return (NULL);
	return (path);
}

char				*bfs(t_lem *lem, t_bfs **bfs_src)
{
	char			*path;
	t_bfs			*bfs;
	t_queue			*queue;

	bfs = *bfs_src ? *bfs_src : new_bfs(lem);
	if (!(queue = new_queue(lem->vrx->name, 1)))
		return (NULL);
	lem->vrx->visit = 1;
	bfs = bfs_algo(lem, queue, bfs);
	path = shortest_path(lem->vrx, bfs);
	//*bfs_src = bfs;
	unvisit(lem->vrx);
	return (path);
}
