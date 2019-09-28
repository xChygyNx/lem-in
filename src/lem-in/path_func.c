/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:10:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/28 14:21:08 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					path_len(t_path *path)
{
	int i;

	i = 0;
	while (path)
	{
		path = path->next;
		++i;
	}
	return (i - 1);
}

int					add_path_to_begin(t_path **begin, t_vrx *vrx)
{
	t_path *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (0);
	path->vrx = vrx;
	if (*begin)
		path->next = *begin;
	else
		path->next = NULL;
	*begin = path;
	return (1);
}

void				visit_listpath(t_listpath *listpath)
{
	t_path *path;

	while (listpath)
	{
		path = listpath->path->next;
		while (path->next)
		{
			if (path->next)
				path->vrx->visit = 1;
			path = path->next;
		}
		listpath = listpath->next;
	}
}
