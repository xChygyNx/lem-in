/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:08:36 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/10 13:31:14 by pcredibl         ###   ########.fr       */
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
	}
	!start || !end ? exit(ft_fprintf(2, "ERROR\n")) : 0;
}

void		check_lem(t_rooms *lem)
{
	start_end(lem);
}