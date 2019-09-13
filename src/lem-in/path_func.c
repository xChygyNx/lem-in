/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:10:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/10 22:32:00 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	t_path *begin;
	t_path *path_node;
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

static t_listpath	*new_listpath(t_lem *lem, char *path)
{
	t_listpath	*listpath_t;
	char		**tab;

	if (!(listpath_t = (t_listpath*)malloc(sizeof(t_listpath))))
		return (NULL);
	if (!(tab = ft_strsplit(path, '|')))
	{
		free(listpath_t);
		return (NULL);
	}
	if (!(listpath_t->path = new_path(lem, tab)))
	{
		free(listpath_t);
		ft_free_arr(tab);
		return (NULL);
	}
	listpath_t->path_len = ft_len_arr(tab);
	listpath_t->next = NULL;
	ft_free_arr(tab);
	return (listpath_t);
}

void				add_listpath(t_lem *lem, char *path)
{
	t_listpath *temp;

	if (!lem->listpath)
	{
		if (!(lem->listpath = new_listpath(lem, path)))
		{
			free(path);
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
			free(path);
			ft_exit(&lem, MALLOC_FAILURE);
		}
	}
}

void				ft_print_paths(t_listpath *listpath)
{
	int		i;
	int		j;
	t_path	*temp;

	j = 0;
	while (listpath)
	{
		i = 0;
		ft_printf("path #%d: |", j);
		temp = listpath->path;
		while (temp->next)
		{
			ft_printf("{red}%s{eoc} -> ", temp->vrx->name);
			++i;
			temp = temp->next;
		}
		ft_printf("{red}%s{eoc}|\n", temp->vrx->name);
		listpath = listpath->next;
		++j;
	}
}
