/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:54:09 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/13 15:11:04 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	there_is_way(t_vrx *vrx_s, t_adj *adj_t, t_bfs *bfs, t_queue *queue)
{
	char	exist_out;

	exist_out = 0;
	if (vrx_s->sep)
	{
		if ((queue->weight > 0 && adj_t->weight < 0) || queue->weight < 0)
		{
			add_queue(&queue, adj_t->name, adj_t->weight);
			add_anc(bfs, adj_t->name, vrx_s->name);
			exist_out = 1;
		}
	}
	else
	{
		add_queue(&queue, adj_t->name, adj_t->weight);
		if (!get_bfs(bfs, adj_t->name)->anc)
			add_anc(bfs, adj_t->name, vrx_s->name);
	}
	return (exist_out);
}

//возвращает 1 если нашел конец 0 - нет
static int	bfs_algo(t_lem *lem, t_queue *queue, t_bfs *bfs)
{
	t_vrx			*vrx_s;
	t_adj			*adj_t;
	char			exist_out;

	while (queue)
	{
		vrx_s = get_vrx(lem->vrx, queue->name);
		adj_t = vrx_s->adj;
		exist_out = 0;
		while (adj_t)
		{
			if (adj_t->dir)
			{
				if (!adj_t->vrx->visit)
					exist_out = there_is_way(vrx_s, adj_t, bfs, queue);
				if (adj_t->vrx->type == END &&\
				((vrx_s->sep && exist_out) || !vrx_s->sep))
					return (free_queue(&queue));
			}
			vrx_s->visit = exist_out || vrx_s->visit || !vrx_s->sep ? 1 : 0;
			adj_t = adj_t->next;
		}
		del_one_queue(&queue);
	}
	return (0);
}

static char	*shortest_path(t_vrx *vrx, t_bfs *bfs)
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

char		*bfs(t_lem *lem, t_bfs **bfs_src)
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
