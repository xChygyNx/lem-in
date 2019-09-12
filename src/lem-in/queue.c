/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:10:44 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/12 16:45:10 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_queue(t_queue **queue)
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
	return (1);
}

void	del_one_queue(t_queue **queue)
{
	t_queue		*temp_q;
	char		weight;

	weight = 0;
	if (queue && *queue)
	{
		temp_q = *queue;
		*queue = temp_q->next;
		free(temp_q->name);
		temp_q->next = NULL;
		free(temp_q);
	}
}

t_queue	*new_queue(char *name, char weight)
{
	t_queue		*new_q;

	if (!(new_q = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	if (!(new_q->name = ft_strdup(name)))
	{
		free(new_q);
		return (NULL);
	}
	new_q->weight = weight;
	new_q->next = NULL;
	return (new_q);
}

void	add_queue(t_queue **queue, char *name, char weight)
{
	t_queue		*new_q;

	if (queue)
	{
		new_q = *queue;
		if (new_q)
		{
			while (new_q->next)
				new_q = new_q->next;
			if (!(new_q->next = new_queue(name, weight)))
				free_queue(queue);
		}
		else
		{
			if (!(*queue = new_queue(name, weight)))
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

t_vrx				*last_vrx_in_queue(t_queue *qu, t_vrx *vrx)
{
	t_vrx	*vrx_t;

	while (qu->next)
		qu = qu->next;
	vrx_t = get_vrx(vrx, qu->name);
	return (vrx_t);
}