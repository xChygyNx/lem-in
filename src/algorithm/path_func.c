/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:10:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/28 15:18:52 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_path_color(t_path *path, char style)
{
	if (style == 0)
		path->color.color = U_RED;
	else if (style == 1)
		path->color.color = U_BLUE;
	else if (style == 2)
		path->color.color = U_GOLD;
	else if (style == 3)
		path->color.color = U_PURPLE;
	else if (style == 4)
		path->color.color = U_BROWN;
	else if (style == 5)
		path->color.color = U_GREEN;
	else if (style == 6)
		path->color.color = U_ORANGE;
	else if (style == 7)
		path->color.color = U_AQUA;
	else if (style == 8)
		path->color.color = U_INDIGO;
	else if (style == 9)
		path->color.color = U_PINK;
	else if (style == 10)
		path->color.color = U_WHITE;
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
