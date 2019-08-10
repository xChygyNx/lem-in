/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yura <yura@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:10:27 by yura              #+#    #+#             */
/*   Updated: 2019/08/06 19:55:39 by yura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

static int			room_info(char *s)
{
	int				spaces;
	int				i;
	char			**tab;

	if (!ft_strcmp(s, "##start"))
		return (START);
	if (!ft_strcmp(s, "##end"))
		return (END);
	if (s[0] == '#')
		return (COMMENT);
	i = -1;
	spaces = 0;
	while (s[++i])
		spaces += s[i] == ' ' ? 1 : 0;
	if (spaces != 2)
		return (-1);
	i = -1;
	tab = ft_strsplit(s, ' ');
	while (++i < 3)
	{
		if ((strlen(tab[i]) != ft_int_len(ft_atoi(tab[i]))\
			|| !ft_isdigit(tab[i][0])) && i != 0)
			return(-1);
	}
	return (0);
}

static t_rooms	*create_lst(char **tab, int type)
{
	t_rooms		*temp;

	temp = (t_rooms*)malloc(sizeof(t_rooms));
	if (!temp)
		exit(ft_fprintf(2, "Error\n"));
	
	temp->name = tab[0];
	temp->x = ft_atoi(tab[1]);
	temp->y = ft_atoi(tab[2]);
	temp->type = type;
	temp->smegh = (char**)malloc(sizeof(char*));
	temp->next = NULL;
	//ft_printf("name = %s, x = %d, y = %d, type = %d\n", temp->name, temp->x, temp->y, temp->type);
	return (temp);
}

static t_rooms	*ft_rooms(char **s)
{
	t_rooms		*lst;
	t_rooms		*begin;
	int			type;

	lst = NULL;
	begin = NULL;
	get_next_line(0, s);
	while ((type = room_info(*s)) != -1)
	{
		//ft_printf("type = %d\n", type);
		type ? get_next_line (0, s): 0;
		if (type == -1)
			break ;
		type = type == 3 ? 0 : type;
		if (!lst)
			lst = create_lst(ft_strsplit(*s, ' '), type);
		else
			lst->next = create_lst(ft_strsplit(*s, ' '), type);
		begin = !begin ? lst : begin;
		lst && lst->next ? lst = lst->next : 0;
		get_next_line(0, s);
	}
	return (begin);
}

void				create_lem(void)
{
	int				ac;
	char    		*line;
	t_rooms			*rooms;

	line = (char*)malloc(sizeof(char));
	if (!line)
		exit(ft_fprintf(2, "Error! Can't allocate memory!\n"));
	get_next_line(0, &line);
	ac = ft_atoi(line);
	ft_printf("ac = %d\n",ac);
	rooms = ft_rooms(&line);
	while (rooms)
	{
		ft_printf("name = %s, x = %d, y = %d, type = %d\n", rooms->name, rooms->x, rooms->y, rooms->type);
		rooms = rooms->next;
	}

}