/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/18 22:15:49 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 		suurballe(t_lem *lem, t_listpath **listpath, int min_paths)
{
	int			i;
	t_path		*path;

	i = min_paths;
	while (i-- && (path = bfs(lem)))
	{
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
	ft_free_one_path(&path);
	i = 0;
	while (i < min_paths && (path = bfs(lem)))
	{
		if (i && path_len(path) > lem->ant_c)
		{
			ft_free_one_path(&path);
			break ;
		}
		redirect_lem(lem, path, OFF);
		if (!add_listpath(listpath, path))
		{
			ft_free_path(listpath);
			ft_free_one_path(&path);
			ft_exit(&lem, MALLOC_FAILURE);
		}
		++i;
	}
	full_renovation_lem(lem);
	return (i);
}

void		find_optimal_path(t_lem *lem, t_ant **army)
{
	int			min_paths;
	int			min_steps;
	int			steps;
	t_listpath	*listpath;
	t_ant		*ants;

	min_paths = 1;
	ants = *army;
	listpath = NULL;
	suurballe(lem, &lem->listpath, min_paths);
	min_steps = routing(lem->listpath, &ants);
	ants = *army;
	while (1)
	{
		min_paths++;
		if (suurballe(lem, &listpath, min_paths) != min_paths)
			break ;
		steps = routing(listpath, &ants);
		if (min_steps >= steps)
		{
//			ft_printf("min_steps = %d, min_path = %d\n", steps, min_paths);
			ft_free_path(&lem->listpath);
			min_steps = steps;
			lem->listpath = listpath;
			listpath = NULL;
			ants = *army;
		}
		else
			break ;
	}
	ft_free_path(&listpath);
	renovate_listpath(lem->listpath);
	offensive(lem, *army);
}

