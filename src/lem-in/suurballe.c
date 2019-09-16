/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/16 23:03:21 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	suurballe(t_lem *lem)
{
	int		i;
	t_path	*path;

	while ((path = bfs(lem)))
	{
//		ft_print_one_path(path);
		redirect_lem(lem, path, OFF);
		if (!dfs(lem, lem->vrx))
		{
			redirect_lem(lem, path, ON);
			unvisit(lem->vrx);
			break ;
		}
		unvisit(lem->vrx);
		ft_free_one_path(&path);
	}
	unvisit(lem->vrx);
	renovation_one_to_two_dir(lem);
	i = 0;
	while ((path = bfs(lem)))
	{
		if (i && path_len(path) > lem->ant_c)
		{
			ft_free_one_path(&path);
			break ;
		}
//		ft_print_one_path(path);
		redirect_lem(lem, path, OFF);
		add_listpath(lem, path);
		++i;
	}
	full_renovation_lem(lem);
}

int		count_steps(t_lem *lem)
{
	t_listpath	*path_t;
	int			a;
	int			w;
	int			z;

	a = 0;
	w = 0;
	path_t = lem->listpath;
	while (path_t)
	{
		a += (path_t->path_len - 1);
		path_t = path_t->next;
		w++;
	}
	if (!((a + (lem->ant_c - w)) % w))
		z = (a + (lem->ant_c - w)) / w;
	else
		z = (a + (lem->ant_c - w)) / w + 1;
	return (z);
}
