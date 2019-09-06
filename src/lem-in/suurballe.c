/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/06 21:49:27 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

typedef struct 			s_listpath
{
	char				**path;
	int					path_len;
	struct	s_listpath	*next;
}						t_listpath;

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

void		suurbale(t_lem *lem)
{
	char	*path;
	int		path_len;

	while ((path = bfs(lem)))
	{
		redirect_lem(lem, path);
		path_len = ft_char_count(path, '|') + 1;
		if (path_len < lem->ant_c)
			break ;
		free(path);
	}
	renovation_one_to_two_dir(lem);
}
