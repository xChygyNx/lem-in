/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:10:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/23 21:47:00 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int			room_info(char *s)
{
	int				i;
	char			**tab;

	if (!ft_strcmp(s, "##start"))
		return (START);
	if (!ft_strcmp(s, "##end"))
		return (END);
	if (*s == '#')
		return (COMMENT);
/*
	Функция должна делать одну определеную вещь, тут же происходит
	и выдача типа комнаты и валидация строки.
*/
	if (ft_char_count(s, ' ') != 2) //если между цифрами больше одного пробела
		return (-1);				//файл не валидный?
	i = -1;
	tab = ft_strsplit(s, ' ');
	while (++i < 3)
	{
		if ((strlen(tab[i]) != ft_int_len(ft_atoi(tab[i]))\
			|| !ft_isdigit(tab[i][0])) && i != 0) // а если второй символ будет не цифра?
			return (-1);
	}
	return (0);
}

static t_rooms		*create_lst(char **tab, int type)
{
	t_rooms		*temp;

	//НУЖНО БОЛЬШЕ ЗАЩИТЫ
	if (!(temp = (t_rooms*)malloc(sizeof(t_rooms))))
		ft_exit(NULL, MALLOC_FAILURE);
	temp->name = tab[0];
	temp->x = ft_atoi(tab[1]);
	temp->y = ft_atoi(tab[2]);
	temp->type = type;
	temp->adj = (t_adj*)malloc(sizeof(t_adj)); //ЕЩЕ БОЛЬШЕ ЗАЩИТЫ
	temp->next = NULL;
	temp->visit = 0;
	//ft_printf("name = %s, x = %d, y = %d, type = %d\n", temp->name, temp->x, temp->y, temp->type);
	return (temp);
}

static t_rooms		*ft_rooms(char **s, int fd)
{
	t_rooms		*lst;
	t_rooms		*begin;
	int			type;

	lst = NULL;
	begin = NULL;
	get_next_line(fd, s); //что будет если вернется -1??
	while ((type = room_info(*s)) != -1)
	{
		type ? get_next_line (fd, s): 0; //что будет если вернется -1??
		while (room_info(*s) > 0)
		{
			type = type == START || type == END ? type : room_info(*s);
			get_next_line(fd, s); //что будет если вернется -1??
		}
		if (room_info(*s) == -1) //еще одна проверка?
			break ;
		type = type == COMMENT ? 0 : type;
		//может сделать чтобы текущую комнату добавлять сразу в конец
		if (!lst)				//если strsplit вернет NULL??
			lst = create_lst(ft_strsplit(*s, ' '), type);
		else						//если strsplit вернет NULL??
			lst->next = create_lst(ft_strsplit(*s, ' '), type);
		begin = !begin ? lst : begin; //это можно вынести за цикл
		lst && lst->next ? lst = lst->next : 0;
		get_next_line(fd, s); //что будет если вернется -1??
		//ft_printf("I'm here\n");
	}
	return (begin);
}

t_rooms				*create_lem(int	fd)
{
	char    		*line;
	t_rooms			*rooms;

	line = NULL;
	if (get_next_line(fd, &line) <= 0)
		ft_exit(NULL, INVALID_INPUT);
	if (!line)
		ft_exit(NULL, INVALID_INPUT);
	rooms = ft_rooms(&line, fd); // отдельно комнаты одельно ребра?
	ft_edge(rooms, &line, fd);
	rooms = check_lem(rooms);
	/*while (rooms)
	{
		ft_printf("name = %s, x = %d, y = %d, type = %d\n", rooms->name, rooms->x, rooms->y, rooms->type);
		rooms = rooms->next;
	}*/
	return (rooms);
}
