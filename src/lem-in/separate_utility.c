/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:56:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/03 22:43:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	rewrite_adj (t_vrx *vrx, char *name)
{
	t_vrx	*temp_v;
	t_adj	*temp_a;

	//ft_printf("I'm in rewrite\n");
	temp_v = vrx;
	while (temp_v)
	{
		temp_a = temp_v->adj;
		//ft_printf("temp_a name = %s | name = %s\n", temp_a->name, name);
		while (temp_a && ft_strcmp(temp_a->name, name))
		{
			//ft_printf("temp_a name in circle = %s\n", temp_a->name);
			temp_a = temp_a->next;
		}
		if (temp_a)
			temp_a->name = ft_strjoin_f(temp_a->name, "_in");
		//ft_printf("temp_a name = %s\n", temp_a->name);
		temp_v = temp_v->next;
	}
}

void	add_adj_sep (t_vrx *src, char *name, int mode)
{
	char	*adj_name;

	//ft_printf("name = %s\n", name);
	adj_name = mode == IN ? ft_strjoin(name, "_in") :\
		ft_strjoin(name, "_out");
	//ft_printf("adj = %p\n", src->adj);
	src->adj = ft_addlst(src->adj, adj_name, 0, 0);
	free(adj_name);
}
