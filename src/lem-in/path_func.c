/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:10:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/18 14:49:58 by pcredibl         ###   ########.fr       */
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

static t_path		*add_vrx_to_path(t_lem *lem, char *name)
{
	t_path *path_t;

	if (!(path_t = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path_t->vrx = get_vrx(lem->vrx, name);
	path_t->next = NULL;
	return (path_t);
}

static t_path		*new_path(t_lem *lem, char **tab)
{
	t_path	*begin;
	t_path	*path_node;
	int		i;

	i = ft_len_arr(tab) - 1;
	if (!(begin = add_vrx_to_path(lem, tab[i--])))
		return (NULL);
	path_node = begin;
	while (i >= 0)
	{
		if (!(path_node->next = add_vrx_to_path(lem, tab[i--])))
		{
			ft_free_one_path(&begin);
			return (NULL);
		}
		path_node = path_node->next;
	}
	return (begin);
}

static t_listpath	*new_listpath(t_lem *lem, t_path *path)
{
	t_listpath	*listpath_t;

	if (!(listpath_t = (t_listpath*)malloc(sizeof(t_listpath))))
		return (NULL);
	listpath_t->path = path;
	listpath_t->path_len = path_len(path);
	listpath_t->next = NULL;
	return (listpath_t);
}

void				add_listpath(t_lem *lem, t_path *path)
{
	t_listpath *temp;

	if (!lem->listpath)
	{
		if (!(lem->listpath = new_listpath(lem, path)))
		{
			ft_free_one_path(&path);
			ft_exit(&lem, MALLOC_FAILURE);
		}
	}
	else
	{
		temp = lem->listpath;
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = new_listpath(lem, path)))
		{
			ft_free_one_path(&path);
			ft_exit(&lem, MALLOC_FAILURE);
		}
	}
	lem->path_c += 1;
}

void				ft_print_one_path(t_path *path)
{
	while (path && path->next)
	{
		ft_printf("{red}%s{eoc} -> ", path->vrx->name);
		path = path->next;
	}
	ft_printf("{red}%s{eoc}|\n", path->vrx->name);
}

void				ft_print_paths(t_listpath *listpath)
{
	int		j;

	j = 0;
	while (listpath)
	{
		ft_printf("path #%d: |", j);
		ft_print_one_path(listpath->path);
		listpath = listpath->next;
		++j;
	}
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

static t_path		*min_path(t_listpath *paths)
{
	int			min_len;
	t_listpath	*min_len_path;

	min_len = MAX_INT;
	min_len_path = NULL;
	while (paths)
	{
		if (paths->path_len < min_len)
		{
			min_len = paths->path_len;
			min_len_path = paths;
		}
		paths = paths->next;
	}
	min_len_path->path_len += 1;
	return (min_len_path->path);
}

int					routing(t_listpath *paths, t_ant **army)
{
	t_path	*min_len_path;
	t_ant	*temp;
	int		steps;
	int		transit_time;

	steps = 0;
	transit_time = paths->path_len - 1;
	while (*army)
	{
		min_len_path = min_path(paths);
		(*army)->path = min_len_path;
		min_len_path == paths->path ? steps++ : 0;
		temp = !(*army)->prev ? *army : NULL;
		*army = (*army)->prev;
	}
	*army = temp;
	//общее количество шагов = время на выпуск всех муравьев + время прохождения
	//последним выпцщенным муравьем самого короткого пути - 1 (потому что
	//когда мы его выпустили, по сути он сделал 1 шаг)
	return (steps + transit_time);
}