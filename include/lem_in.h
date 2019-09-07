/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/07 13:43:22 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf.h"
# include <stdio.h>

# define START 1
# define END 2
# define COMMENT 3

# define ON 1
# define OFF 0

/*
 * Errors from 100 to infinity
 */

# define INVALID_INPUT 100
# define START_END 101
# define DOUBLE_VRX 102
# define ONE_COMPONENT 103
# define WROTE_ANTS 104

typedef struct			s_adj
{
	char				*name;
	struct s_adj		*next;
	char				weight;
	char				dir;
}						t_adj;

typedef struct			s_lem
{
	struct s_vrx		*vrx;
	int					ant_c;   //кол-во муравьев
	int					vert_c;  //кол-во вершин
	int					edge_c;  //кол-во ребер
	struct s_path	*path;   //связный список непересекающихся путей
	char				*map;
	char				*line;
}						t_lem;

typedef struct			s_vrx
{
	struct s_adj		*adj;
	char				*name;
	int					x;
	int					y;
	char				type;
	struct s_vrx		*next;
	char				visit;
	char				sep;
}						t_vrx;

typedef struct			s_bfs
{
	char				*name;
	char				*anc;
	struct s_bfs		*next;
}						t_bfs;

typedef struct			s_queue
{
	char				*name;
	struct s_queue		*next;
}						t_queue;

typedef struct 			s_path
{
	char				**path;
	int					path_len;
	struct	s_path	*next;
}						t_path;

void					ft_exit(t_lem **lem, int err);

t_lem					*create_lem(int fd);

void					ft_edge(t_lem *lem, int fd);

void					check_lem(t_lem *lem);

void					is_two_vert(char **vertexes);

t_adj					*ft_addlst(t_adj *adj, char *elem, char wght, char dir);

void					unvisit(t_vrx *vertex);

void					ft_del_lem(t_lem **lem_to_del);

int						ft_validate_vrx(char **map);

int 					ft_validate_edge(char **map);

int						exist_vertex(t_vrx *vrx, char **vertexes);

int						invalid_com(char *str);

void					add_adj(t_lem *lem, char **v);

void					change_dir(t_lem *lem, char *start, char *end, char dir);

void					redirect_lem(t_lem *lem, char *shortest_path, char tumbler);

t_vrx					*get_vrx(t_vrx *vrx, char *name);

t_adj					*get_adj(t_adj *adj, char *name);

t_bfs					*find_bfs(char *name, t_bfs *bfs);

char					*bfs(t_lem *lem);

int						dfs(t_lem *lem, char *name);

void					renovation_one_to_two_dir(t_lem *lem);

void					full_renovation_lem(t_lem *lem);

void					ft_free_path(t_path **listpath_to_del);

t_path					*add_path(t_path *begin, char *path);

/*
 * UTILITY FUNCTIONS
 */

void					ft_print_lem_info(t_lem *lem);

void					ft_print_paths(t_path *listpath);

#endif
