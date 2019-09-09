/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/09 23:01:36 by astripeb         ###   ########.fr       */
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
	struct s_path		*path;   //связный список непересекающихся путей
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
	char				weight;
	struct s_queue		*next;
}						t_queue;

typedef struct 			s_path
{
	char				**path;
	int					path_len;
	struct	s_path		*next;
}						t_path;

void					ft_exit(t_lem **lem, int err);

/*
 * CREATE LEM FUNCTIONS
 */

t_lem					*create_lem(int fd);

void					ft_edge(t_lem *lem, int fd);

t_adj					*ft_addlst(t_adj *adj, char *elem, char wght, char dir);

void					add_adj(t_lem *lem, char **v);

void					ft_del_lem(t_lem **lem_to_del);

/*
 * CHECK & VALIDATE FUNCTIONS
 */

void					check_lem(t_lem *lem);

void					is_two_vert(char **vertexes);

int						ft_validate_vrx(char **map);

int 					ft_validate_edge(char **map);

int						exist_vertex(t_vrx *vrx, char **vertexes);

int						invalid_com(char *str);

/*
 * DIRECTION FUNCTIONS
 */

void					change_dir(t_lem *lem, char *start, char *end, char dir);

void					redirect_lem(t_lem *lem, char *short_path, char tumbler);

void					renovation_one_to_two_dir(t_lem *lem);

void					full_renovation_lem(t_lem *lem);

void					unvisit(t_vrx *vertex);

/*
 * DEEP-FIRST SEARCH FUNCTIONS
 */

int						dfs(t_lem *lem, char *name);

/*
 * PATH FUNCTIONS
 */

void					ft_free_path(t_path **listpath_to_del);

t_path					*add_path(t_path *begin, char *path);

/*
 * BREADTH-FIRST SEARCH FUNCTIONS
 */

char					*bfs(t_lem *lem, t_bfs **bfs);

t_bfs					*add_bfs(char *name, char *anc, t_bfs *bfs, t_lem *lem);

t_bfs					*new_bfs(t_lem *lem);

void					free_bfs(t_bfs *bfs);

t_bfs					*find_bfs(char *name, t_bfs *bfs);

/*
 * QUEUE FUNCTIONS
 */

t_queue					*new_queue(char *name, char weight);

void					add_queue(t_queue **queue, char *name, char weight);

void					free_queue(t_queue **queue);

char					del_one_queue(t_queue **queue);

/*
 * UTILITY FUNCTIONS
 */

t_vrx					*get_vrx(t_vrx *vrx, char *name);

t_adj					*get_adj(t_adj *adj, char *name);

void					ft_print_lem_info(t_lem *lem);

void					ft_print_paths(t_path *listpath);


void					suurballe(t_lem *lem);

#endif
