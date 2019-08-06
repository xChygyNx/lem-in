/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_anthill.c                                   :+:      :+:    :+:   */
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
		if (strlen(s[i]) != ft_int_len(ft_atoi(s[i]))\
			|| !ft_isdigit(s[i][0]))
			return(-1);
	return (0);
}

static t_anthill	*create_lst(t_anthill *lst, char **tab, int type)
{
	t_anthill		*temp;

	temp = (t_anthill*)malloc(sizeof(t_anthill));
	if (!temp)
		exit(ft_fprintf(2, "Error\n"));
	
	temp->num_room = tab[0];
	temp->x = tab[1];
	temp->y = tab[2];
	temp->type = type;
	return (temp);
}

static t_anthill	*ft_rooms(char **s)
{
	t_anthill		*lst;
	t_anthill		*begin;
	int				type

	get_next_line(0, s)
	while (type = room_info(*s) != -1)
	{
		!type? get_next_line (0, s): 0;
		lst = create_lst(lst, ft_strsplit(*s), type); 
		begin = !begin ? lst : begin;
		get_next_line(0, s);
	}
	return (begin);
}

void				create_anthill(void)
{
	int				ac;
	char    		*buf;
	t_anthill		*rooms;

	buf = (char*)malloc(sizeof(char) * 50);
	ft_bzero((void*)buf, 50);
	printf("I'm here\n");
	get_next_line(0, &buf);
	ac = ft_atoi(buf);
	ft_printf("ac = %d\n", ac);
	rooms = ft_rooms(&buf);

}