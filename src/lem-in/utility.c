/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/13 17:10:30 by pcredibl         ###   ########.fr       */
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