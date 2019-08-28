/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:08:36 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/28 13:28:17 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		first_start(t_lem *lem)
{
	t_vrx	*begin;
	t_vrx	*temp;
	t_vrx	*vrx;

	vrx = lem->vrx;
	if (vrx->type != 1)
	{
		begin = vrx;
		while (vrx->next && vrx->next->type != 1)
			vrx = vrx->next;
		temp = vrx->next;
		vrx->next = vrx->next->next;
		temp->next = begin;
		lem->vrx = temp;
	}
}

static int		check_start_end(t_vrx *vrx)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (vrx)
	{
		start +=vrx->type == START ? 1 : 0;
		end += vrx->type == END ? 1 : 0;
		if (start == 2 || end == 2)
			return (0);
		vrx = vrx->next;

	}
	return (!start || !end ? 0 : 1);
}

static int		check_double_vertex(t_vrx *vrx)
{
	t_vrx	*cur;

	cur = vrx;
	while (cur->next)
	{
		vrx = cur->next;
		while (vrx)
		{
			if (!ft_strcmp(cur->name, vrx->name) ||\
				(cur->x == vrx->x && cur->y == vrx->y))
				return (0);
			vrx = vrx->next;
		}
		cur = cur->next;
	}
	return (1);
}

static int		find_end(t_adj *cur, t_vrx *begin)
{
	t_vrx	*temp;
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
		{
			temp->adj = start;
			return (1);
		}
		temp->adj = temp->adj->next;
	}
	temp->adj = start;
	return (0);
}

void			check_lem(t_lem *lem)
{
	//ft_printf("I'm come in\n");
	if (!check_start_end(lem->vrx))
		ft_exit(&lem, START_END);
	//ft_printf("I'm come in\n");
	first_start(lem);
	if (!check_double_vertex(lem->vrx))
		ft_exit(&lem, DOUBLE_VRX);
	if (!find_end(lem->vrx->adj, lem->vrx))
		ft_exit(&lem, ONE_COMPONENT);
	unvisit(lem->vrx);
}

/*
static void		find_end(t_adj *cur, t_vrx *begin, int *res)
{
	t_vrx *temp;
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
