/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:31:55 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/30 21:29:59 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_dijk		*dijk_lst(char *s)
{
	t_dijk			*lst;

	lst = (t_dijk*)malloc(sizeof(t_dijk));
	lst->vrx = ft_strdup(s);
	lst->anc = NULL;
	lst->dist = MAX_INT;
	lst->next = NULL;
	return (lst);
}

static t_dijk		*new_dijk(t_lem *lem)
{
	t_dijk			*begin;
	t_dijk			*dijk;
	t_vrx			*temp;

	/*temp = lem->vrx;
	while (lem->vrx)
	{
		printf("vrx name = %s\n", lem->vrx->name);
		lem->vrx = lem->vrx->next;
	}*/
	temp = lem->vrx;
	begin = dijk_lst(temp->name);
	dijk = begin;
	temp = temp->next;
	while (temp)
	{
		dijk->next = dijk_lst(temp->name);
		temp = temp->next;
		dijk = dijk->next;
	}
	return (begin);
}

void				dijkstra(t_lem *lem)
{
	t_dijk			*dijk;

	dijk = new_dijk(lem);
	while (dijk)
	{
		print_dijk(dijk);
		dijk = dijk->next;
	}
}