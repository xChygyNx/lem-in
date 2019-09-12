/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:54:09 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/12 18:09:46 by pcredibl         ###   ########.fr       */
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
		//if (vrx_s->type == END)
		//	return (free_queue(&queue));
		adj_t = vrx_s->adj;
		exist_out = 0;
		while (adj_t)
		{
			if (!adj_t->dir)
			{
				adj_t = adj_t->next;
				continue ;
			}
			vrx_e = get_vrx(lem->vrx, adj_t->name);
			if (!vrx_e->visit)
			{
				if (vrx_s->sep)
				{
					if ((queue->weight > 0 && adj_t->weight < 0) || queue->weight < 0)
					{
						add_queue(&queue, adj_t->name, adj_t->weight);
						!get_bfs(bfs, vrx_e->name)->anc ? add_anc(bfs, adj_t->name, vrx_s->name) : 0;
						exist_out = 1;
					}
				}
				else
				{
					add_queue(&queue, adj_t->name, adj_t->weight);
					!get_bfs(bfs, vrx_e->name)->anc ? add_anc(bfs, adj_t->name, vrx_s->name) : 0;
					//vrx_s->visit = 1;
				}
			}
			//ft_printf("name = %s\n", last_vrx_in_queue(queue, lem->vrx)->name);
			if (last_vrx_in_queue(queue, lem->vrx)->type == END)
				return (free_queue(&queue));
			adj_t = adj_t->next;
		}
		vrx_s->visit = exist_out || vrx_s->visit || !vrx_s->sep ? 1 : 0;
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
