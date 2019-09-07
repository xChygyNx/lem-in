/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:44 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/07 15:41:13 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_qu(t_queue *qu)
{
	t_queue	*temp_q;
	while (qu)
	{
		temp_q = qu->next;
		free(qu->name);
		qu->next = NULL;
		free(qu);
		qu = temp_q;
	}
}

void	del_elem_qu(t_queue **queue)
{
	t_queue	*temp_q;

	temp_q = *queue;
	*queue = (*queue)->next;
	free(temp_q->name);
	temp_q ? temp_q->next = NULL : 0;
	temp_q ? free(temp_q) : 0;
	temp_q = NULL;
}

t_queue	*add_qu(t_queue *queue, char *name)
{
	t_queue	*start;

	start = queue;
	while (queue && queue->next)
		queue = queue->next;
	queue->next = (t_queue*)malloc(sizeof(t_queue));
	queue = queue->next;
	queue->name = ft_strdup(name);
	queue->next = NULL;
	return(start);
}

t_queue	*new_queue (t_lem *lem)
{
	t_queue	*queue;
	char	*name;

	queue = (t_queue*)malloc(sizeof(t_queue));
	if (!(name = ft_strdup(lem->vrx->name)))
		ft_exit (&lem, MALLOC_FAILURE);
	lem->vrx->visit = 1;
	queue->name = name;
	queue->next = NULL;
	return (queue);
}
