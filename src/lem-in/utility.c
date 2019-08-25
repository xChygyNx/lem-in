/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/25 18:35:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adj	*ft_addlst(t_adj *adj, char *elem)
{
	t_adj	*begin;

	if (adj)
	{
		begin = adj;
		while (adj->next)
			adj = adj->next;
		if (!(adj->next = (t_adj*)malloc(sizeof(t_adj))))
			return (NULL);
		adj = adj->next;
		adj->name = ft_strdup(elem);
		adj->next = NULL;
	}
	else
	{
		if (!(begin = (t_adj*)malloc(sizeof(t_adj))))
			return (NULL);
		begin->name = ft_strdup(elem);
		begin->next = NULL;
	}
	return (begin);
}

void	unvisit(t_rooms *lem)
{
	while (lem)
	{
		lem->visit = 0;
		lem = lem->next;
	}
}

void	ft_print_lem_info(t_lem *lem)
{
	t_rooms		*room;
	t_adj		*adj;

	ft_printf("ants  = %d\n", lem->ant_c);
	ft_printf("rooms = %d\n", lem->vert_c);
	ft_printf("edges = %d\n", lem->edge_c);
	room = lem->rooms;
	while (room)
	{
		ft_printf("-----------------------\n");
		ft_printf("name = %s\nx = %d\ny = %d\ntype = %d\nvisit = %d\n",\
		room->name, room->x, room->y, room->type, room->visit);
		ft_printf("adj_rooms = ");
		adj = room->adj;
		while (adj->next)
		{
			ft_printf("%s, ", adj->name);
			adj = adj->next;
		}
		ft_printf("%s\n", adj->name);
		room = room->next;
	}
}

int		ft_char_count(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (*str++)
	{
		if (*str == c)
			++i;
	}
	return (i);
}

int		ft_len_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}
