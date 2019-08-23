/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/23 20:47:04 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_adj	*ft_addlst(t_adj *adj, char *elem)
{
	t_adj	*begin;
	if (adj->name)
	{
		begin = adj;
		while (adj->next)
			adj = adj->next;
		adj->next = (t_adj*)malloc(sizeof(t_adj));
		adj = adj->next;
		adj->name = ft_strdup(elem);
		adj->name = ft_strcpy(adj->name, elem);
		adj->next = NULL;
	}
	else
	{
		begin = (t_adj*)malloc(sizeof(t_adj));
		begin->name = ft_strdup(elem);
		begin->name = ft_strcpy(begin->name, elem);
		begin->next = NULL;
	}
	return(begin);
}

void	unvisit(t_rooms *lem)
{
	while (lem)
	{
		lem->visit = 0;
		lem = lem->next;
	}
}

void	ft_free_rooms(t_rooms ** rooms)
{
	return ;
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
