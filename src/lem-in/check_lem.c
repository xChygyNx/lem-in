/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:08:36 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/27 00:14:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		first_start(t_lem *lem)
{
	t_rooms	*begin;
	t_rooms	*temp;
	t_rooms *room;

	room = lem->rooms;
	if (room->type != 1)
	{
		begin = room;
		while (room->next && room->next->type != 1)
			room = room->next;
		temp = room->next;
		room->next = room->next->next;
		temp->next = begin;
		lem->rooms = temp;
	}
}

static int		check_start_end(t_rooms *room)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (room)
	{
		start +=room->type == START ? 1 : 0;
		end += room->type == END ? 1 : 0;
		if (start == 2 || end == 2)
			return (0);
		room = room->next;

	}
	return (!start || !end ? 0 : 1);
}

static int		check_double_vertex(t_rooms *room)
{
	t_rooms	*cur;

	cur = room;
	while (cur->next)
	{
		room = cur->next;
		while (room)
		{
			if (!ft_strcmp(cur->name, room->name) ||\
				(cur->x == room->x && cur->y == room->y))
				return (0);
			room = room->next;
		}
		cur = cur->next;
	}
	return (1);
}

static int		find_end(t_adj *cur, t_rooms *begin)
{
	t_rooms *temp;
	t_adj	*start;

	if (!cur)
		return (0);
	temp = begin;
	while (ft_strcmp(temp->name, cur->name))
		temp = temp->next;
	if (temp->type == END)
		return (1);
	if (temp->visit)
		return (0);
	temp->visit = 1;
	start = temp->adj;
	while (temp->adj)
	{
		if (find_end(temp->adj, begin))
			return (1);
		temp->adj = temp->adj->next;
	}
	temp->adj = start;
	return (0);
}

void			check_lem(t_lem *lem)
{
	first_start(lem);
	if (!check_start_end(lem->rooms))
		ft_exit(&lem, START_END);
	if (!check_double_vertex(lem->rooms))
		ft_exit(&lem, DOUBLE_VRX);
	if (!find_end(lem->rooms->adj, lem->rooms))
		ft_exit(&lem, ONE_COMPONENT);
	unvisit(lem->rooms);
}

/*
static void		find_end(t_adj *cur, t_rooms *begin, int *res)
{
	t_rooms *temp;
	t_adj	*start;

	usleep(50000);
	if (*res || !cur)
		return ;
	temp = begin;
	while (ft_strcmp(temp->name, cur->name))
		temp = temp->next;
	*res = temp->type == 2 ? 1 : *res;
	if (*res || temp->visit)
		return ;
	temp->visit = 1;
	start = temp->adj;
	while (temp->adj && !(*res))
	{
		find_end(temp->adj, begin, res);
		temp->adj = temp->adj->next;
	}
	temp->adj = start;
}
*/
