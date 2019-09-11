/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:44 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/11 20:20:44 by pcredibl         ###   ########.fr       */
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
			second->from = NULL;
			free(second->name);
			free(second);
		}
		*queue = NULL;
	}
}

void	del_one_queue(t_queue **queue)
{
	t_queue		*temp_q;
	char		weight;

	if (queue && *queue)
	{
		temp_q = *queue;
		*queue = temp_q->next;
		temp_q->from = NULL;
		free(temp_q->name);
		temp_q->next = NULL;
		free(temp_q);
	}
}

t_queue	*new_queue(char *name, t_vrx *from)
{
	t_queue		*new_q;

	if (!(new_q = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	new_q->from = from;
	if (!(new_q->name = ft_strdup(name)))
	{
		free(new_q);
		return (NULL);
	}
	new_q->next = NULL;
	return (new_q);
}

void	add_queue(t_queue **queue, char *name, t_vrx *from)
{
	t_queue		*new_q;


	if (queue)
	{
		new_q = *queue;
		if (new_q)
		{
			while (new_q->next)
				new_q = new_q->next;
			if (!(new_q->next = new_queue(name, from)))
				free_queue(queue);
		}
		else
		{
			if (!(*queue = new_queue(name, from)))
				free_queue(queue);
		}
	}
}

void				ft_print_queue(t_queue *queue)
{
	ft_printf("queue : |");
	while (queue->next)
	{
		ft_printf("{red}%s{eoc}, ", queue->name);
		queue = queue->next;
	}
	ft_printf("{red}%s{eoc}|\n", queue->name);
}
