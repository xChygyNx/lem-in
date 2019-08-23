/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/23 21:44:34 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf.h"
# include <stdio.h>

# define START 1
# define END 2
# define COMMENT 3

/*
 * Errors from 100 to infinity
 */

# define INVALID_INPUT 100

typedef struct			s_adj
{
	char				*name;
	struct s_adj		*next;
}						t_adj;

typedef struct			s_lem
{
	struct s_rooms		*rooms;
	int					ant_c;  //кол-во муравьев
	int					vert_c;  //кол-во вершин
	int					edge_c;  //кол-во ребер
	char				**path; //что будем в пути хранить?
}						t_lem;

typedef struct			s_rooms
{
	struct s_adj		*adj;
	char				*name;
	int					x;
	int					y;
	int					type;
	struct s_rooms		*next;
	int					visit;
}						t_rooms;

void					ft_exit(t_rooms **lem, int err);

t_rooms					*create_lem(int fd);

void					ft_edge(t_rooms *len, char **line, int fd);

t_rooms					*check_lem(t_rooms *lem);

void					is_two_vert(char **vertexes);

void					exist_vertex(char **vertexes, t_rooms *lem);

t_adj					*ft_addlst(t_adj *adj, char *elem);

t_rooms					*check_adj(t_rooms *lem);

void					unvisit(t_rooms *lem);

void					ft_free_rooms(t_rooms **rooms);

/*
 * UTILITY FUNCTIONS
 */

int		ft_char_count(char *str, char c);

#endif
