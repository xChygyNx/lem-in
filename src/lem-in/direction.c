/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:42:46 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/05 13:58:30 by pcredibl         ###   ########.fr       */
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

	if (!(vrxs = ft_strsplit(shortest_path, '|')))
		ft_exit(&lem, MALLOC_FAILURE);
	i = ft_len_arr(vrxs) - 2;
	vrx_t = lem->vrx;
	rewrite_adj(vrx_t, vrxs);
	while (vrx_t && i > 0)
	{
		vrx_t = lem->vrx;
		while (vrx_t && ft_strcmp(vrxs[i], vrx_t->name))
			vrx_t = vrx_t->next;
		if (vrx_t && !ft_strcmp(vrxs[i], vrx_t->name))
			vrx_in_out(vrxs[i], vrxs, lem->vrx);
		--i;
	}
	vrx_t = lem->vrx;
	path_adj(vrx_t, vrxs);
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
