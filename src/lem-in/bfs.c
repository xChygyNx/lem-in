/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:54:09 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/11 00:53:32 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//возвращает 1 если нашел конец 0 - нет

static int		bfs_algo(t_lem *lem, t_queue *queue, t_bfs *bfs)
{
	t_vrx			*vrx_s; //start vrx
	t_vrx			*vrx_e; //end vrx
	t_adj			*adj_t;

	while (queue)
	{
//		ft_print_queue(queue);
		vrx_s = get_vrx(lem->vrx, queue->name);
		if (vrx_s->type == END)
		{
			free_queue(&queue);
			return (1);
		}
		adj_t = vrx_s->adj;
		while (adj_t)
		{
			if (!adj_t->dir)
			{
				adj_t = adj_t->next;
				continue ;
			}
			vrx_e = get_vrx(lem->vrx, adj_t->name);
			if (adj_t->weight > 0 && vrx_e->sep)
				vrx_e->by_pos = ON;
			if (!vrx_e->visit && (!vrx_s->by_pos || adj_t->weight < 0))
			{
				add_queue(&queue, adj_t->name, adj_t->weight);
				add_anc(bfs, adj_t->name, vrx_s->name);
				vrx_e->visit = 1;
			}
			adj_t = adj_t->next;
		}
		vrx_s->by_pos = OFF;
		del_one_queue(&queue);
	}
	return (0);
}

static char			*shortest_path(t_vrx *vrx, t_bfs *bfs)
{
	t_bfs		*temp_bfs;
	char		*path;

	if (!(path = ft_strnew(0)))
		return (NULL);
	while (vrx && vrx->type != END)
		vrx = vrx->next;
	temp_bfs = get_bfs(bfs, vrx->name);
	while (temp_bfs && temp_bfs->anc)
	{
		if (!(path = ft_strjoin_f(path, temp_bfs->name)))
			return (NULL);
		if (!(path = ft_strjoin_f(path, "|")))
			return (NULL);
		temp_bfs = temp_bfs->anc;
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

	bfs = *bfs_src ? *bfs_src : bfs_list(lem);
	if (!(queue = new_queue(lem->vrx->name, 1)))
		return (NULL);
	lem->vrx->visit = 1;
	path = NULL;
	if (bfs_algo(lem, queue, bfs))
		path = shortest_path(lem->vrx, bfs);
	unvisit(lem->vrx);
	clean_anc(bfs);
	*bfs_src = bfs;
	return (path);
}
