/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:33:16 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/22 17:30:01 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_max_x(t_vrx *vrx)
{
	int max;

	max = 0;
	while (vrx)
	{
		if (vrx->x > max)
			max = vrx->x;
		vrx = vrx->next;
	}
	return (max);
}

static int	get_max_y(t_vrx *vrx)
{
	int max;

	max = 0;
	while (vrx)
	{
		if (vrx->y > max)
			max = vrx->y;
		vrx = vrx->next;
	}
	return (max);
}

void		margin_vertex(t_lem *lem)
{
	int		margin_x;
	int		margin_y;
	t_vrx	*vrx;

	vrx = lem->vrx;
	margin_x = (WIN_WIDTH - (2 * INDENT)) / get_max_x(vrx);
	margin_y = (WIN_HEIGHT - (2 * INDENT)) / get_max_y(vrx);
	while (vrx)
	{
		vrx->x = vrx->x * margin_x + INDENT;
		vrx->y = vrx->y * margin_y + INDENT;
		vrx = vrx->next;
	}
}
