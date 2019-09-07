/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 11:10:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/07 11:36:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_listpath 			*new_path(char	 *path)
{
	t_listpath *new;

	if (!(new = (t_listpath*)malloc(sizeof(t_listpath))))
		return (NULL);
	if (!(new->path = ft_strsplit(path, '|')))
	{
		free(new);
		return (NULL);
	}
	new->path_len = ft_len_arr(new->path);
	new->next = NULL;
	return (new);
}

t_listpath			*add_path(t_listpath *begin, char *path)
{
	t_listpath *temp;

	if (!begin)
	{
		if (!(begin = new_path(path)))
			return (NULL);
	}
	else
	{
		temp = begin;
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = new_path(path)))
		{
			ft_free_path(&begin);
			return (NULL);
		}
	}
	return (begin);
}

void				ft_print_paths(t_listpath *listpath)
{
	int	i;
	int	j;

	j = 0;
	while (listpath)
	{
		i = 0;
		ft_printf("path #%d: |", j);
		while (i < listpath->path_len - 1)
		{
			ft_printf("{red}%s{eoc} -> ", listpath->path[i]);
			++i;
		}
		ft_printf("{red}%s{eoc}|\n", listpath->path[i]);
		listpath = listpath->next;
		++j;
	}
}
