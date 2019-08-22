/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/22 21:37:53 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf.h"

# define	START 1
# define	END 2
# define 	COMMENT 3

typedef struct 			s_adj
{
	char				*name;
	struct s_adj		*next;
}						t_adj;

typedef struct 			s_lem
{
	struct s_rooms		*rooms;
	int					ac;
	int					vc;
	int					ec;
	char				**path;
}						t_lem;

typedef struct 			s_rooms
{
	struct s_adj		*adj;
	char				*name;
	int					x;
	int					y;
	int					type;
	struct s_rooms		*next;
	int					visit;
}						t_rooms;

t_rooms					*create_lem(int fd);

void					ft_edge(t_rooms *len, char **line, int fd);

t_rooms					*check_lem(t_rooms *lem);

void					is_two_vert(char **vertexes);

void					exist_vertex(char **vertexes, t_rooms *lem);

t_adj					*ft_addlst(t_adj *adj, char *elem);

t_rooms					*check_adj(t_rooms *lem);

void					unvisit(t_rooms *lem);

#endif
