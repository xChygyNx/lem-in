/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:54:09 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/07 13:11:12 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			free_qu(t_queue *qu)
{
	t_queue			*temp_q;
	while (qu)
	{
		temp_q = qu->next;
		free(qu->name);
		qu->next = NULL;
		free(qu);
		qu = temp_q;
	}
}

static void			del_elem_qu(t_queue **queue)
{
	t_queue			*temp_q;

	temp_q = *queue;
	*queue = (*queue)->next;
	free(temp_q->name);
	temp_q->next = NULL;
	free(temp_q);
	temp_q = NULL;
}

static t_bfs		*add_bfs(char *name, char *anc, t_bfs *bfs, t_lem *lem)
{
	t_bfs			*temp;
	t_bfs			*start;

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

static t_bfs		*new_bfs(t_lem *lem)
{
	t_bfs			*begin;
	t_bfs			*bfs;
	t_vrx			*temp_vrx;

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

static t_queue		*add_qu(t_queue *queue, char *name)
{
	t_queue			*start;
	
	start = queue;
	while (queue && queue->next)
		queue = queue->next;
	queue->next = (t_queue*)malloc(sizeof(t_queue));
	queue = queue->next;
	queue->name = ft_strdup(name);
	//ft_printf("queue name = %s\n", queue->name);
	queue->next = NULL;
	return(start);
}

static t_queue		*new_queue (t_lem *lem)
{
	t_queue		*queue;
	char		*name;

	queue = (t_queue*)malloc(sizeof(t_queue));
	//ft_printf("lem->vrx->name = %s\n", lem->vrx->name);
	if (!(name = ft_strdup(lem->vrx->name)))
		ft_exit (&lem, MALLOC_FAILURE);
	//ft_printf("name = %s\n", name);
	lem->vrx->visit = 1;
	queue->name = name;
	queue->next = NULL;
	return (queue);
}

static t_bfs		*bfs_algo(t_lem *lem, t_queue *queue)
{
	t_vrx			*temp_vrx;
	t_vrx			*temp2_vrx;
	t_bfs			*bfs;
	t_adj			*temp_adj;

	bfs = new_bfs (lem);
	/*while (queue)
	{
		ft_printf("queue->name = %s", queue->name);
		queue = queue->next;
	}*/
	while (queue)
	{
		temp_vrx = get_vrx(lem->vrx, queue->name);
		if (temp_vrx->type == END)
			break ;
		temp_adj = temp_vrx->adj;
		while (temp_adj)
		{
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

static char			*print_short_path(t_vrx *vrx, t_bfs *bfs)
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

static void			free_bfs(t_bfs *bfs)
{
	t_bfs			*temp;

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

char				*bfs(t_lem *lem)
{
	t_bfs			*bfs;
	char			*path;
	t_queue			*queue;

	queue = new_queue(lem);
	bfs = bfs_algo(lem, queue);
	//if (!(path = print_short_path(lem->vrx, bfs)))
		//ft_exit(&lem, MALLOC_FAILURE);
	path = print_short_path(lem->vrx, bfs);
	ft_printf("path = %s\n", path);
	//free_bfs(bfs);
	return (path);
}
