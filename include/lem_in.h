/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/18 22:01:15 by astripeb         ###   ########.fr       */
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

# define MAX_INT 2147483647

/*
 * Errors from 100 to infinity
 */

# define INVALID_INPUT 100
# define START_END 101
# define DOUBLE_VRX 102
# define ONE_COMPONENT 103
# define WROTE_ANTS 104

# define SEP 32

typedef struct			s_adj
{
	char				*name;
	struct s_adj		*next;
	struct s_vrx		*vrx; 	 //добавил в adj указатель на t_vrx
	char				weight;  //можно обращаться к данным вершины вот так: adj_t->vrx->var
	char				dir;
}						t_adj;

typedef struct			s_lem
{
	struct s_vrx		*vrx;
	int					ant_c;   	//кол-во муравьев
	int					vert_c;  	//кол-во вершин
	int					edge_c;  	//кол-во ребер
	struct s_listpath	*listpath;   //связный список непересекающихся путей
	int					path_c;
	char				*map;
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
	int					ant;
	struct s_vrx		*anc;

}						t_vrx;

typedef struct			s_bfs
{
	struct s_vrx		*vrx;
	struct s_bfs		*anc;
	struct s_bfs		*next;
}						t_bfs;

typedef struct			s_queue
{
	struct s_vrx		*vrx;
	char				weight;
	struct s_queue		*next;
}						t_queue;

typedef struct 			s_listpath
{
	int					path_len;
	struct	s_path		*path;
	struct	s_listpath	*next;
}						t_listpath;

typedef struct 			s_path
{
	struct	s_vrx		*vrx;
	struct	s_path		*next;
}						t_path;

typedef struct			s_ant
{
	int					serial_number;
	struct s_path		*path;
	struct s_ant		*next;
	struct s_ant		*prev;
}						t_ant;

void					ft_exit(t_lem **lem, int err);

/*
 * CREATE LEM FUNCTIONS
 */

t_lem					*create_lem(int fd);

void					ft_edge(t_lem *lem, char **lines);

t_adj					*ft_addlst(t_adj *adj, char *elem, char wght, char dir);

void					add_adj(t_lem *lem, char **v);

void					add_link_adj_to_vrx(t_lem *lem);

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

void					change_dir(t_lem *lem, t_vrx *vrx, char *end, char dir);

void					redirect_lem(t_lem *lem, t_path *path, char tumbler);

void					renovation_one_to_two_dir(t_lem *lem);

void					full_renovation_lem(t_lem *lem);

void					unvisit(t_vrx *vertex);

/*
 * DEEP-FIRST SEARCH FUNCTIONS
 */

int						dfs(t_lem *lem, t_vrx *vrx);

/*
 * PATH FUNCTIONS
 */

void					ft_free_path(t_listpath **listpath_to_del);

void					ft_free_one_path(t_path **path_to_del);

int						add_listpath(t_listpath **listpath, t_path *path);

int						add_path_to_begin(t_path **begin, t_vrx *vrx);

int						routing(t_listpath *paths, t_ant **army);

int						path_len(t_path *path);

void					renovate_listpath(t_listpath *listpath);

/*
 * BREADTH-FIRST SEARCH FUNCTIONS
 */

t_path					*bfs(t_lem *lem);

t_bfs					*bfs_list(t_lem *lem);

t_bfs					*new_bfs(t_vrx *vrx);

void					add_anc(t_bfs *bfs, char *name, char *anc);

void					free_bfs(t_bfs **bfs);

t_bfs					*get_bfs(t_bfs *bfs, char *name);

/*
 * QUEUE FUNCTIONS
 */

t_queue					*new_queue(t_vrx *vrx, char weight);

void					add_queue(t_queue **queue, t_vrx *vrx, char weight);

int						free_queue(t_queue **queue);

void					del_one_queue(t_queue **queue);


/*
 * UTILITY FUNCTIONS
 */

t_vrx					*get_vrx(t_vrx *vrx, char *name);

t_adj					*get_adj(t_adj *adj, char *name);

void					ft_print_lem_info(t_lem *lem);

void					ft_print_paths(t_listpath *listpath);

void					ft_print_queue(t_queue *queue);

void					ft_print_one_path(t_path *path);

/*
 * PUSH THE BUTTON
 */

int						suurballe(t_lem *lem, t_listpath **listpath, int min_paths);

void					find_optimal_path(t_lem *lem, t_ant **army);

char					*read_from_file_to_var(int fd);

/*
 * ATN'S FUNCTIONS
 */

void		dissolve_army(t_ant **first_soldier);

void		first_soldier_commission(t_ant **army);

void		soldiers_commission(t_ant **army);

t_ant		*new_soldier(int serial_number);

t_ant		*create_army(int number_of_soldiers);

void		tactical_moves(t_lem *lem, t_ant *army, t_listpath *listpath);

void		offensive(t_lem *lem, t_ant *army);

void		order_army(t_ant **army);

void		pereklichka(t_ant *army);

#endif
