/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:39:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/08/27 22:15:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_exit(t_lem **lem, int err)
{
	ft_del_lem(lem);
	if (err == INVALID_INPUT)
		ft_fprintf(2, "Error: Invalid map\n");
	else if (err == START_END)
		ft_fprintf(2, "Error: Two starts/ends, or not start/end\n");
	else if (err == DOUBLE_VRX)
		ft_fprintf(2, "Error: Duplicate vertex or same coordinates\n");
	else if (err == ONE_COMPONENT)
		ft_fprintf(2, "Error: Start & end situated in different \
connected components\n");
	else
		perror("Error: ");
	exit(err);
}

static void		ft_free_adj(t_adj **adj_to_del)
{
	t_adj	*adj;
	t_adj	*temp;

	if (adj_to_del)
	{
		adj = *adj_to_del;
		while (adj)
		{
			temp = adj;
			adj = adj->next;
			free(temp->name);
			free(temp);
		}
		adj_to_del = NULL;
	}
}

static void		ft_free_vrxs(t_vrx **vrx_to_del)
{
	t_vrx		*vrx;
	t_vrx		*temp;

	if (vrx_to_del)
	{
		vrx = *vrx_to_del;
		while (vrx)
		{
			temp = vrx;
			ft_free_adj(&vrx->adj);
			free(vrx->name);
			vrx = vrx->next;
			free(temp);
		}
		vrx_to_del = NULL;
	}
}

void		ft_del_lem(t_lem **lem_to_del)
{
	t_lem	*lem;

	if (lem_to_del)
	{
		lem = *lem_to_del;
		ft_free_vrxs(&lem->vrx);
		lem->path ? ft_free_arr(lem->path) : 0;
		ft_strdel(&lem->map);
		ft_strdel(&lem->line);
		free(lem);
		lem_to_del = NULL;
	}
}
