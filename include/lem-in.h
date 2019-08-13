/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:57:27 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/13 17:20:39 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "libftprintf.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
}						t_rooms;


t_rooms					*create_lem(int fd);

void					ft_edge(t_rooms *len, char **line, int fd);

void					check_lem(t_rooms *lem);

void					is_two_vert(char **vertexes);

void					exist_vertex(char **vertexes, t_rooms *lem);

t_adj					*ft_addlst(t_adj *adj, char *elem);
#endif
