/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:56:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/05 10:26:10 by pcredibl         ###   ########.fr       */
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

t_vrx	*vrx_copy (t_vrx *src, t_vrx *all_vrx)
{
	t_vrx	*copy;

	copy = (t_vrx*)malloc(sizeof(t_vrx));
	copy->x = src->x;
	copy->y = src->y;
	copy->type = src->type;
	copy->visit = src->visit;
	copy->sep = src->sep;
	copy->next = src;
	copy->adj = NULL;
//	add_adj_sep (copy, src->name, OUT);
	copy->name = ft_strjoin(src->name, "_in");
	return (copy);
}

int	in_path(char *name, char **path)
{
	int		i;

	i = -1;
	while (path[++i])
		if (!ft_strcmp(name, path[i]))
			return(1);
	return (0);
}