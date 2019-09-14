/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/14 14:00:21 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	suurballe(t_lem *lem)
{
	char	*path;
	int		i;
	t_bfs	*bfs_src;

	bfs_src = NULL;
	while ((path = bfs(lem, &bfs_src)))
	{
		ft_printf("path#1 = %s\n", path);
		redirect_lem(lem, path, OFF);
		if (!dfs(lem, lem->vrx->name))
		{
			redirect_lem(lem, path, ON);
			break ;
		}
		unvisit(lem->vrx);
		free(path);
	}
	unvisit(lem->vrx);
	renovation_one_to_two_dir(lem);
	i = 0;
	while ((path = bfs(lem, &bfs_src)))
	{
		ft_printf("path#2 = %s\n", path);
		redirect_lem(lem, path, OFF);
		if (i && ft_char_count(path, SEP) + 1 > lem->ant_c)
		{
			free(path);
			break ;
		}
		add_listpath(lem, path);
		free(path);
		++i;
	}
	full_renovation_lem(lem);
	free_bfs(&bfs_src);
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
