/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:20:36 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/13 20:21:20 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	find_end(t_adj *cur, t_rooms *begin, int *res)
{
	t_rooms *temp;
	
	usleep(50000);
	//ft_printf("cur = %s, begin = %s, res = %d\n", cur->name, begin->name, *res);
	if (*res)
		return ;
	temp = begin;
	//ft_printf("cur = %s, temp = %s, cond = %d\n", cur->name, temp->name, ft_strcmp(temp->name, cur->name));
	while (ft_strcmp(temp->name, cur->name))
		temp = temp->next;
	*res = temp->type == 2 ? 1 : *res;
	//ft_printf("cur = %s, temp = %s, type = %d, res = %d\n", cur->name, temp->name, temp->type, *res);
	if (*res || temp->visit)
		return ;
	temp->visit = 1;
	while (temp->adj)
	{
		find_end(temp->adj, begin, res);
		temp->adj = temp->adj->next;
	}
}

void		check_adj(t_rooms *lem)
{
	t_rooms	*begin;
	t_rooms	*temp;
	int		res;

	res = 0;
	if (lem->type != 1)
	{
		begin = lem;
		/*while (lem)
		{
			ft_printf("name = %s, x = %d, y = %d, type = %d\n", lem->name, lem->x, lem->y, lem->type);
			lem = lem->next;
		}
		lem = begin;*/
		while (lem->next && lem->next->type != 1)
			lem = lem->next;
		temp = lem->next;
		lem->next = lem->next->next;
		temp->next = begin;
		lem = temp;
		/*ft_printf("#######################################################################\n");
		while (lem)
		{
			ft_printf("name = %s, x = %d, y = %d, type = %d\n", lem->name, lem->x, lem->y, lem->type);
			lem = lem->next;
		}
		lem = temp;*/
	}
	/*else
	{
		while (lem)
		{
			ft_printf("name = %s, x = %d, y = %d, type = %d\n", lem->name, lem->x, lem->y, lem->type);
			lem = lem->next;
		}
	}*/
	//lem->visit = 1;
	find_end(lem->adj, lem, &res);
	//ft_printf("res = %d\n", res);
	!res ? exit(ft_fprintf(2, "ERROR, (start & end situated in different connected components)\n")) : 0;
}