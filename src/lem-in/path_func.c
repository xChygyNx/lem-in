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

t_path				*add_vrx_to_path(t_lem *lem, char *name)
{
	t_path *new_path;

	if (!(new_path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	new_path->vrx = get_vrx(lem->vrx, name);
	new_path->next = NULL;
	return (new_path);
}

t_listpath 			*new_path(t_lem *lem, char *path)
{
	t_listpath	*new_listpath;
	t_path		*new_path;
	char		**tab;
	int		i;

	if (!(new_listpath = (t_listpath*)malloc(sizeof(t_listpath))))
		ft_exit(&lem, MALLOC_FAILURE);
	if (!(tab = ft_strsplit(path, '|')))
	{
		free(new_listpath);
		ft_exit(&lem, MALLOC_FAILURE);
	}
	i = ft_len_arr(tab) - 1;
	if (!(new_listpath->path = add_vrx_to_path(lem, tab[i--])))
	{
		free(new_listpath);
		ft_exit(&lem, MALLOC_FAILURE);
	}
	new_path = new_listpath->path;
	while (i >= 0)
	{
		if (!(new_path->next = add_vrx_to_path(lem, tab[i--])))
		{
			free(new_listpath);
			ft_exit(&lem, MALLOC_FAILURE);
		}
		new_path = new_path->next;
	}
	new_listpath->path_len = ft_len_arr(tab);
	new_listpath->next = NULL;
	ft_free_arr(tab);
	return (new_listpath);
}

t_listpath			*add_path(t_lem *lem, t_listpath *begin, char *path)
{
	t_listpath *temp;

	if (!begin)
	{
		if (!(begin = new_path(lem, path)))
			return (NULL);
	}
	else
	{
		temp = begin;
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = new_path(lem, path)))
		{
			ft_free_path(&begin);
			ft_exit(&lem, MALLOC_FAILURE);
		}
	}
	return (begin);
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
