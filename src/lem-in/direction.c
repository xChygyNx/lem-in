/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:58:29 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/10 21:49:37 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	change_eds_wght(t_lem *lem, char *start, char *end, int weight)
{
	t_vrx	*vrx_t;
	t_adj	*adj_t;

	if ((vrx_t = get_vrx(lem->vrx, start)))
	{
		if ((adj_t = get_adj(vrx_t->adj, end)))
			adj_t->weight = weight;
	}
}

static void	separate_vrxs(t_lem *lem, char **vrxs, char tumbler)
{
	t_vrx	*vrx_t;
	int		i;

	i = ft_len_arr(vrxs) - 2;
	while (i > 0)
	{
		if ((vrx_t = get_vrx(lem->vrx, vrxs[i])))
			vrx_t->sep = tumbler;
		--i;
	}
}

void		change_dir(t_lem *lem, char *start, char *end, char dir)
{
	t_vrx	*vrx_t;
	t_adj	*adj_t;

	if ((vrx_t = get_vrx(lem->vrx, start)))
	{
		if ((adj_t = get_adj(vrx_t->adj, end)))
			adj_t->dir = dir;
	}
}

void		redirect_lem(t_lem *lem, char *shortest_path, char tumbler)
{
	char	**vrxs;
	int		i;

	if (!(vrxs = ft_strsplit(shortest_path, '|')))
		ft_exit(&lem, MALLOC_FAILURE);
	i = ft_len_arr(vrxs) - 1;
	while (i > 0)
	{
		change_dir(lem, vrxs[i], vrxs[i - 1], tumbler);
		change_eds_wght(lem, vrxs[i], vrxs[i - 1], !tumbler ? OFF : ON);
		change_eds_wght(lem, vrxs[i - 1], vrxs[i], !tumbler ? -1 : 1);
		--i;
	}
	separate_vrxs(lem, vrxs, !tumbler ? ON : OFF);
	ft_free_arr(vrxs);
}