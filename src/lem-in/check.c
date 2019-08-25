/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:08:36 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/25 18:31:15 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		start_end(t_rooms *lem)
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
		start == 2 || end == 2 ? exit(ft_fprintf(2, "ERROR: two starts or ends\n")) : 0;
		lem = lem->next;

	}
	!start || !end ? exit(ft_fprintf(2, "ERROR: not start or ends\n")) : 0;
}

static void		check_vert(t_rooms *lem)
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
				exit(ft_fprintf(2, "ERROR: duplicate vertex\n"));
			lem = lem->next;
		}
		cur = cur->next;
	}
	//!ft_strlen(cur->adj) ? exit(ft_fprintf(2, "ERROR (isolate vertex)\n")) : 0;
}

t_rooms			*check_lem(t_rooms *lem)
{
	start_end(lem);
	//ft_printf("name = %s\n", lem->name);
	check_vert(lem);
	lem = check_adj(lem);
	unvisit(lem);

	return (lem);
}
