/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:48:13 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/13 20:59:49 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			vrx_info(char *s)
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

static t_vrx		*create_vrx(char **tab, int type)
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
	temp->sep = OFF;
	return (temp);
}

static int			add_vrx(t_vrx **begin, char *line, int type)
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

static int			ft_vertex(t_lem *lem, char **lines)
{
	int			type;
	int			i;

	i = 0;
	type = 0;
	lem->vert_c = 0;
	while (lines[i] && vrx_info(lines[i]) != -1)
	{
		if (vrx_info(lines[i]) > 0)
		{
			type = vrx_info(lines[i]) == COMMENT\
			? type : vrx_info(lines[i]);
			++i;
			continue ;
		}
		if (!add_vrx(&lem->vrx, lines[i], type))
			ft_exit(&lem, INVALID_INPUT);
		lem->vert_c += 1;
		type = 0;
		++i;
	}
	return (i);
}

t_lem				*create_lem(int fd)
{
	t_lem			*lem;
	char			**lines;
	int				i;

	if (!(lem = (t_lem*)malloc(sizeof(t_lem))))
		ft_exit(NULL, MALLOC_FAILURE);
	lem->map = read_from_file_to_var(fd);
	lem->listpath = NULL;
	lem->vrx = NULL;
	i = 0;
	if (!(lines = ft_strsplit(lem->map, '\n')))
		ft_exit(&lem, MALLOC_FAILURE);
	while (lines[i] && invalid_com(lines[i]))
		++i;
	if (ft_strlen(lines[i]) == 0 || ft_isdigitstr(lines[i]) < 1)
		ft_exit(&lem, INVALID_INPUT);
	lem->ant_c = ft_atoi(lines[i]);
	if (ft_int_len(lem->ant_c) != ft_strlen(lines[i]) || lem->ant_c <= 0)
		ft_exit(&lem, INVALID_INPUT);
	i += ft_vertex(lem, &lines[i + 1]);
	ft_edge(lem, &lines[i + 1]);
	add_link_adj_to_vrx(lem);
	check_lem(lem);
	ft_free_arr(lines);
	return (lem);
}
