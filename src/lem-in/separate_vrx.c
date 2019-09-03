/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_vrx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:48:14 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/03 23:04:24 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	in_path(char *name, char **path)
{
	int		i;

	i = -1;
	while (path[++i])
		if (!ft_strcmp(name, path[i]))
			return(1);
	return (0);
}

static t_vrx	*vrx_copy (t_vrx *src, t_vrx *all_vrx)
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

static void	add_in(t_vrx *vrx, char **path, t_vrx *all_vrx)
{
	t_vrx		*new;
	t_vrx		*temp;

	temp = all_vrx;
	while (temp->next != vrx)
		temp = temp->next;
	new = vrx_copy(vrx, all_vrx);
	temp->next = new;
	rewrite_adj(all_vrx, vrx->name);
}

static void	add_out(t_vrx *out, char **path)
{
	t_adj	*temp;

	add_adj_sep(out, out->name, IN);
	temp = out->adj;
	while (temp)
	{
		if (!ft_strncmp(out->name, temp->name, ft_strlen(out->name)))
		{
			temp->dir = ON;
			temp->weight = 0;
		}
		else
			temp->dir = in_path(temp->name, path) ? 0 : temp->dir;
		temp = temp->next;
	}
	out->name = ft_strjoin_f(out->name, "_out");
}

void    	vrx_in_out(char *vrx_name, char **vrx_path, t_vrx *all_vrx)
{
    t_vrx	*vrx_out;
    t_vrx	*temp;

    temp = all_vrx;
    while (ft_strcmp(temp->name, vrx_name))
		temp = temp->next;
	vrx_out = temp;
	add_in(vrx_out, vrx_path, all_vrx);
	add_out(vrx_out, vrx_path);
}
