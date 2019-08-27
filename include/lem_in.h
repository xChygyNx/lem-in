/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/27 22:09:56 by astripeb         ###   ########.fr       */
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
# define START_END 101
# define DOUBLE_VRX 102
# define ONE_COMPONENT 103

typedef struct			s_adj
{
	char				*name;
	struct s_adj		*next;
}						t_adj;

typedef struct			s_lem
{
	struct s_vrx		*vrx;
	int					ant_c;   //кол-во муравьев
	int					vert_c;  //кол-во вершин
	int					edge_c;  //кол-во ребер
	char				**path;  //что будем в пути хранить?
	char				*map;
	char				*line;
}						t_lem;

typedef struct			s_vrx
{
	struct s_adj		*adj;
	char				*name;
	int					x;
	int					y;
	int					type;
	struct s_vrx		*next;
	int					visit;
}						t_vrx;

void					ft_exit(t_lem **lem, int err);

t_lem					*create_lem(int fd);

void					ft_edge(t_lem *lem, int fd);

void					check_lem(t_lem *lem);

void					is_two_vert(char **vertexes);

t_adj					*ft_addlst(t_adj *adj, char *elem);

void					unvisit(t_vrx *vertex);

void					ft_del_lem(t_lem **lem_to_del);

int						ft_validate_vrx(char **map);

int 					ft_validate_edge(char **map);

/*
 * UTILITY FUNCTIONS
 */

int						ft_char_count(char *str, char c);

int						ft_len_arr(char **arr);

void					ft_print_lem_info(t_lem *lem);

#endif
