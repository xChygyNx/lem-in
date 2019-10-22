/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/22 21:44:25 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf.h"
# include "visual.h"
# include <stdio.h>

# define START 1
# define END 2
# define COMMENT 3

# define ON 1
# define OFF 0

# define MAX_INT 2147483647

# define INVALID_INPUT 100
# define START_END 101
# define DOUBLE_VRX 102
# define ONE_COMPONENT 103
# define SDL_INIT_ERROR 104
# define SDL_WIN_ERROR 105
# define USAGE 106

# define SEP 32

typedef struct			s_adj
{
	char				*name;
	struct s_adj		*next;
	struct s_vrx		*vrx;
	char				weight;
	char				dir;
}						t_adj;

typedef struct			s_lem
{
	struct s_vrx		*vrx;
	int					ant_c;
	int					vert_c;
	int					edge_c;
	struct s_listpath	*listpath;
	char				*map;
	struct s_visual		*vis;
	char				visualization;
	char				without_map;
	char				design_map;		//влаг для выравнивания координат комнат (для лучшей наглядности)
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
	struct s_visual		*vis;
}						t_vrx;

typedef struct			s_queue
{
	struct s_vrx		*vrx;
	char				weight;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_listpath
{
	int					path_len;
	struct s_path		*path;
	struct s_listpath	*next;
}						t_listpath;

typedef struct			s_path
{
	struct s_vrx		*vrx;
	struct s_path		*next;
}						t_path;

typedef struct			s_ant
{
	int					serial_number;
	struct s_path		*path;
	struct s_ant		*next;
	struct s_ant		*prev;
}						t_ant;

void					ft_exit(t_lem **lem, int err);

t_lem					*create_lem(int fd);

void					check_flags(char **av, t_lem *lem);

void					ft_edge(t_lem *lem, char **lines);

t_adj					*ft_addlst(t_adj *adj, char *elem, char wght);

void					add_adj(t_lem *lem, char **v);

void					add_link_adj_to_vrx(t_lem *lem);

void					ft_del_lem(t_lem **lem_to_del);

char					vrx_info(char *s);

void					check_lem(t_lem *lem);

void					is_two_vert(char **vertexes);

int						ft_validate_vrx(char **map);

int						ft_validate_edge(char **map);

int						exist_vertex(t_vrx *vrx, char **vertexes);

int						invalid_com(char *str);

void					change_dir(t_vrx *vrx, char *end, char dir);

void					redirect_lem(t_path *path, char tumbler);

void					renovation_one_to_two_dir(t_lem *lem);

void					full_renovation_lem(t_lem *lem);

void					unvisit(t_vrx *vertex);

int						dfs(t_lem *lem, t_vrx *vrx);

void					ft_free_path(t_listpath **listpath_to_del);

void					ft_free_one_path(t_path **path_to_del);

int						add_listpath(t_listpath **listpath, t_path *path);

int						add_path_to_begin(t_path **begin, t_vrx *vrx);

int						routing(t_listpath *paths, t_ant *army);

int						path_len(t_path *path);

void					renovate_listpath(t_listpath *listpath);

t_path					*bfs(t_lem *lem);

t_queue					*new_queue(t_vrx *vrx, char weight);

void					add_queue(t_queue **queue, t_vrx *vrx, char weight);

int						free_queue(t_queue **queue);

void					del_one_queue(t_queue **queue);

t_vrx					*get_vrx(t_vrx *vrx, char *name);

t_adj					*get_adj(t_adj *adj, char *name);

int						suurballe(t_lem *lem, t_listpath **listpath,\
						int min_paths);

void					find_optimal_path(t_lem *lem, t_ant *army);

void					dissolve_army(t_ant **first_soldier);

void					first_soldier_commission(t_ant **army);

void					soldiers_commission(t_ant **army);

t_ant					*new_soldier(int serial_number);

t_ant					*create_army(int number_of_soldiers);

void					tactical_moves(t_lem *lem, t_ant *army,\
						t_listpath *listpath);

void					offensive(t_lem *lem, t_ant *army);

void					visit_listpath(t_listpath *listpath);

/*
** VISIO FUNCTIONS
*/

void					init_vis(t_lem *lem);

void					margin_vertex(t_lem *lem);

void					draw_graph(t_lem *lem);

#endif
