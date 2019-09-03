/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:42:46 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/03 21:55:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		change_eds_wght(t_lem *lem, char *start, char *end, int weight)
{
	t_vrx	*vrx_t;
	t_adj	*adj_t;

	vrx_t = lem->vrx;
	while (vrx_t && ft_strcmp(start, vrx_t->name))
		vrx_t = vrx_t->next;
	adj_t = vrx_t ? vrx_t->adj : NULL;
	while (adj_t && ft_strcmp(end, adj_t->name))
		adj_t = adj_t->next;
	adj_t ? adj_t->weight = weight : 0;
}

static void			separate_vrxs(t_lem *lem, char *shortest_path)
{
	char	**vrxs;
	t_vrx	*vrx_t;

	int		i;

	//ft_printf("\nshortest path = %s\n", shortest_path);
	if (!(vrxs = ft_strsplit(shortest_path, '|')))
		ft_exit(&lem, MALLOC_FAILURE);
	i = ft_len_arr(vrxs) - 2;
	vrx_t = lem->vrx;
	//ft_printf("vrx = %s, i = %d\n", vrx_t->name, i);
	while (vrx_t && i > 0)
	{
		vrx_t = lem->vrx;
		while (vrx_t && ft_strcmp(vrxs[i], vrx_t->name))
			vrx_t = vrx_t->next;
		//ft_printf("vrx_t name = %s, vrxs[%d] = %s\n", vrx_t->name, i, vrxs[i]);
		if (vrx_t && !ft_strcmp(vrxs[i], vrx_t->name))
		//ft_printf("\n+++++++++++++++++++++I'm here++++++++++++++++++++\n");
			//vrx_t->sep = ON;
			vrx_in_out(vrxs[i], vrxs, lem->vrx);
		--i;
	}
	ft_free_arr(vrxs);
}

void			redirect_lem(t_lem *lem, char *shortest_path)
{
	char	**vrxs;
	int		i;

	if (!(vrxs = ft_strsplit(shortest_path, '|')))
		ft_exit(&lem, MALLOC_FAILURE);
	i = ft_len_arr(vrxs) - 1;
	while (i > 0)
	{
		change_dir(lem, vrxs[i], vrxs[i - 1]);
		change_eds_wght(lem, vrxs[i], vrxs[i - 1], 0);
		change_eds_wght(lem, vrxs[i - 1], vrxs[i], -1);
		--i;
	}
	ft_free_arr(vrxs);
	separate_vrxs(lem, shortest_path);
}
