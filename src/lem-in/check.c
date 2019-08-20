/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:08:36 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/20 20:57:50 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	start_end(t_rooms *lem)
{
	//t_rooms	*begin;
	int		start;
	int		end;

	start = 0;
	end = 0;
	//begin = len;
	while (lem)
	{
		start += lem->type == START ? 1 : 0;
		end += lem->type == END ? 1 : 0;
		start == 2 || end == 2 ? exit(ft_fprintf(2, "ERROR1\n")) : 0;
		lem = lem->next;
	}
	!start || !end ? exit(ft_fprintf(2, "ERROR2\n")) : 0;
}

static void	check_vert(t_rooms *lem)
{
	t_rooms	*cur;

	cur = lem;
	while (cur->next)
	{
		lem = cur->next;
		//ft_printf("name = %s, adj =%s, len = %zu\n", cur->name, cur->adj, ft_strlen(cur->adj));
		//!ft_strlen(cur->adj) ? exit(ft_fprintf(2, "ERROR (isolate vertex)\n")) : 0;
		while (lem)
		{
			if (!ft_strcmp(cur->name, lem->name) ||\
				(cur->x == lem->x && cur->y == lem->y))
				exit(ft_fprintf(2, "ERROR (duplicate vertex)\n"));
			lem = lem->next;
		}
		cur = cur->next;
	}
	//!ft_strlen(cur->adj) ? exit(ft_fprintf(2, "ERROR (isolate vertex)\n")) : 0;
}

void		is_two_vert(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	i == 2 ? 0 : exit(ft_fprintf(2 , "ERROR3\n"));
}

void		exist_vertex(char **vertexes, t_rooms *lem)
{
	int		v1;
	int		v2;

	v1 = 0;
	v2 = 0;
	while ((!v1 || !v2) && lem)
	{
		//ft_printf("name1 = %s, vert1 = %s, vert2 = %s\n", lem->name, vertexes[0], vertexes[1]);
		v1 += !ft_strcmp(lem->name, vertexes[0]) ? 1 : 0;
		v2 += !ft_strcmp(lem->name, vertexes[1]) ? 1 : 0;
		if (v1 && v2)
			break ;
		lem = lem->next;
	}
	//ft_printf("v1 = %d, v2 = %d, cond = %d\n", v1, v2, !v1 || !v2);
	!v1 || !v2 ? exit(ft_fprintf(2, "ERROR4\n")) : 0;
}

t_rooms		*check_lem(t_rooms *lem)
{
	start_end(lem);
	//ft_printf("name = %s\n", lem->name);
	check_vert(lem);
	lem = check_adj(lem);
	return (lem);
}