/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:10:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/28 17:44:10 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_path_color(t_lem *lem)
{
	int			i;
	t_listpath	*tmp_list;

	tmp_list = lem->listpath;
	i = 0;
	while (tmp_list)
	{
		lem->listpath->path->color.color = i % 11 == 0 ? U_RED : 0;
		lem->listpath->path->color.color = i % 11 == 1 ? U_BLUE : 0;
		lem->listpath->path->color.color = i % 11 == 2 ? U_GOLD : 0;
		lem->listpath->path->color.color = i % 11 == 3 ? U_PURPLE : 0;
		lem->listpath->path->color.color = i % 11 == 4 ? U_BROWN : 0;
		lem->listpath->path->color.color = i % 11 == 5 ? U_GREEN : 0;
		lem->listpath->path->color.color = i % 11 == 6 ? U_ORANGE : 0;
		lem->listpath->path->color.color = i % 11 == 7 ? U_AQUA : 0;
		lem->listpath->path->color.color = i % 11 == 8 ? U_INDIGO : 0;
		lem->listpath->path->color.color = i % 11 == 9 ? U_PINK : 0;
		lem->listpath->path->color.color = i % 11 == 10 ? U_WHITE : 0;
		i++;
		tmp_list = tmp_list->next; 
	}
}

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
			path->vrx->visit = 1;
			path = path->next;
		}
		listpath = listpath->next;
	}
}
