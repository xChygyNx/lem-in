/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:26:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/23 19:45:59 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		rooms_count(t_lem *lem)
{
	int		i;
	t_vrx	*cur;

	i = 0;
	cur = lem->vrx;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

void	design_map(t_lem *lem)
{
	int		in_row;
	int		room_count;
	int		i;
	int		j;
	t_vrx	*cur_vrx;

	i = 0;
	cur_vrx = lem->vrx;
	room_count = rooms_count(lem);
	in_row = ft_sqrt(room_count);
	while (room_count)
	{
		j = 0;
		while (j < in_row + 1 && room_count)
		{
			cur_vrx->x = j;
			cur_vrx->y = i + j % 3;
			j++;
			cur_vrx = cur_vrx->next;
			room_count--;
		}
		i++;
	}
}
