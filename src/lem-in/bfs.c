/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:54:09 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/11 19:45:01 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//возвращает 1 если нашел конец 0 - нет

static int		bfs_algo(t_lem *lem, t_queue *queue, t_bfs *bfs)
{
	t_vrx			*vrx_s; //start vrx
	t_vrx			*vrx_e; //end vrx
	t_adj			*adj_t;
	int				exist_out;

	while (queue)
	{
//		ft_print_queue(queue);
		vrx_s = get_vrx(lem->vrx, queue->name);
		if (vrx_s->type == END)
		{
			free_queue(&queue);
			return (1);
		}
		exist_out = 0;
		vrx_s->visit && vrx_s->type != START ? add_anc(bfs, vrx_s->name, queue->from->name) : 0;
		if (!vrx_s->visit || vrx_s->type == START)
		{
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
					add_queue(&queue, adj_t->name, vrx_s);
					add_anc(bfs, adj_t->name, vrx_s->name);
					exist_out = 1;
				}
				adj_t = adj_t->next;
			}
		}
		vrx_s->by_pos = OFF;
		vrx_s->visit = exist_out ? 1 : 0;
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
	if (!(queue = new_queue(lem->vrx->name, NULL)))
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
