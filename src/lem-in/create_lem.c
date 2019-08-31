/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:48:13 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/31 17:32:32 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char			vrx_info(char *s)
{
	if (!ft_strcmp(s, "##start"))
		return (START);
	if (!ft_strcmp(s, "##end"))
		return (END);
	if (*s == '#')
		return (COMMENT);
	if (ft_char_count(s, ' ') != 2)
		return (-1);
	return (0);
}

static t_vrx		*create_vrx(char **tab, char type)
{
	t_vrx		*temp;

	if (!(temp = (t_vrx*)malloc(sizeof(t_vrx))))
		return (NULL);
	if (!(temp->name = ft_strdup(tab[0])))
	{
		free(temp);
		return (NULL);
	}
	temp->x = ft_atoi(tab[1]);
	temp->y = ft_atoi(tab[2]);
	if (temp->x < 0 || temp->y < 0)
	{
		free(temp->name);
		free(temp);
		return (NULL);
	}
	temp->type = type;
	temp->adj = NULL;
	temp->next = NULL;
	temp->visit = 0;
	temp->sep = 0;
	return (temp);
}

static int			add_vrx(t_vrx **begin, char *line, char type)
{
	t_vrx		*temp;
	char		**split;
	int			flag;

	flag = 1;
	if (!(split = ft_strsplit(line, ' ')) || !ft_validate_vrx(split))
		return (0);
	if (*begin)
	{
		temp = *begin;
		while (temp->next)
			temp = temp->next;
		if (!(temp->next = create_vrx(split, type)))
			flag = 0;
	}
	else
	{
		if (!(*begin = create_vrx(split, type)))
			flag = 0;
	}
	ft_free_arr(split);
	return (flag);
}

static void			ft_vertex(t_lem *lem, int fd)
{
	int			type;

	type = 0;
	lem->vert_c = 0;
	while (get_next_line(fd, &lem->line) > 0 && vrx_info(lem->line) != -1)
	{
		if (!(lem->map = ft_strjoin_f(lem->map, "\n"))\
		|| !(lem->map = ft_strjoin_f(lem->map, lem->line)))
			ft_exit(&lem, MALLOC_FAILURE);
		if (vrx_info(lem->line) > 0)
		{
			type = vrx_info(lem->line) == COMMENT\
			? type : vrx_info(lem->line);
			free(lem->line);
			continue ;
		}
		if (!add_vrx(&lem->vrx, lem->line, type))
			ft_exit(&lem, INVALID_INPUT);
		lem->vert_c += 1;
		free(lem->line);
		type = 0;
	}
}

t_lem				*create_lem(int fd)
{
	t_lem			*lem;

	if (!(lem = (t_lem*)malloc(sizeof(t_lem))))
		ft_exit(NULL, MALLOC_FAILURE);
	lem->path = NULL;
	lem->vrx = NULL;
	lem->line = NULL;
	lem->map = NULL;
	while ((get_next_line(fd, &lem->line) > 0) && invalid_com(lem->line))
		;
	if (!lem->line || ft_strlen(lem->line) == 0\
		|| ft_isdigitstr(lem->line) < 1)
		ft_exit(&lem, INVALID_INPUT);
	lem->ant_c = ft_atoi(lem->line);
	if (ft_int_len(lem->ant_c) != ft_strlen(lem->line) || lem->ant_c <= 0)
		ft_exit(&lem, INVALID_INPUT);
	if (!(lem->map = ft_strjoin_s("", lem->line)))
		ft_exit(&lem, MALLOC_FAILURE);
	ft_vertex(lem, fd);
	ft_edge(lem, fd);
	check_lem(lem);
	return (lem);
}
