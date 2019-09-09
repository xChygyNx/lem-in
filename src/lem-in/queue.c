/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:44 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/09 23:10:30 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_queue(t_queue **queue)
{
	t_queue		*first;
	t_queue		*second;

	if (queue)
	{
		first = *queue;
		while (first)
		{
			second = first;
			first = first->next;
			free(second->name);
			free(second);
		}
		*queue = NULL;
	}
}

char	del_one_queue(t_queue **queue)
{
	t_queue		*temp_q;
	char		weight;

	if (queue && *queue)
	{
		temp_q = *queue;
		*queue = (*queue)->next;
		weight = temp_q->weight;
		free(temp_q->name);
		free(temp_q);
	}
	else
		return (0);
	return (weight);
}

t_queue	*new_queue(char *name, char weight)
{
	t_queue		*queue;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	if (!(queue->name = ft_strdup(name)))
	{
		free(queue);
		return (NULL);
	}
	queue->weight = weight;
	queue->next = NULL;
	return (queue);
}

void	add_queue(t_queue **queue, char *name, char weight)
{
	t_queue		*new_q;


	new_q = *queue;
	if (new_q)
	{
		while (new_q->next)
			new_q = new_q->next;
		if (!(new_q = new_queue(name, weight)))
			free_queue(queue);
	}
	else
	{
		if (!(*queue = new_queue(name, weight)))
			free_queue(queue);
	}

}
