/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/19 19:57:05 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*first_pass(t_lem *lem, int min_paths)
{
	int			i;
	t_path		*path;

	i = min_paths;
	while (i-- && (path = bfs(lem)))
	{
		redirect_lem(path, OFF);
		if (!dfs(lem, lem->vrx))
		{
			redirect_lem(path, ON);
			unvisit(lem->vrx);
			break ;
		}
		unvisit(lem->vrx);
		ft_free_one_path(&path);
	}
	return (path);
}

int				suurballe(t_lem *lem, t_listpath **listpath, int min_paths)
{
	int			i;
	t_path		*path;

	path = first_pass(lem, min_paths);
	unvisit(lem->vrx);
	renovation_one_to_two_dir(lem);
	ft_free_one_path(&path);
	i = 0;
	while (i < min_paths && (path = bfs(lem)))
	{
		redirect_lem(path, OFF);
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

static void		search_optimal_count_of_paths(t_lem *lem, t_listpath *paths,\
				int min_steps, t_ant **army)
{
	int			min_paths;
	int			steps;
	t_ant		*ants;

	min_paths = 1;
	ants = *army;
	while (1)
	{
		min_paths++;
		if (suurballe(lem, &paths, min_paths) != min_paths)
			return ;
		steps = routing(paths, &ants);
		if (min_steps >= steps)
		{
			ft_free_path(&lem->listpath);
			min_steps = steps;
			lem->listpath = paths;
			paths = NULL;
			ants = *army;
		}
		else
			return ;
	}
}

void			find_optimal_path(t_lem *lem, t_ant **army)
{
	int			min_steps;
	t_listpath	*listpath;
	t_ant		*ants;

	ants = *army;
	listpath = NULL;
	suurballe(lem, &lem->listpath, 1);
	min_steps = routing(lem->listpath, &ants);
	search_optimal_count_of_paths(lem, listpath, min_steps, army);
	ft_free_path(&listpath);
	renovate_listpath(lem->listpath);
	offensive(lem, *army);
}
