/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:08:36 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/10 15:30:30 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	start_end(t_rooms *len)
{
	t_rooms	*begin;
	int		start;
	int		end;

	start = 0;
	end = 0;
	begin = len;
	while (len)
	{
		start += len->type == START ? 1 : 0;
		end += len->type == END ? 1 : 0;
		start == 2 || end == 2 ? exit(ft_fprintf(2, "ERROR\n")) : 0;
		len = len->next;
	}
	!start || !end ? exit(ft_fprintf(2, "ERROR\n")) : 0;
}

void		size_arr(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	i == 2 ? 0 : exit(ft_fprintf(2 , "ERROR\n"));
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
	!v1 || !v2 ? exit(ft_fprintf(2, "ERROR\n")) : 0;
}

void		check_lem(t_rooms *lem)
{
	start_end(lem);
}