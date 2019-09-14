/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:26:10 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/14 11:57:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

typedef struct		s_ant
{
	struct s_vrx	*vrx;
	struct s_path	*path;
	struct s_ant	*next;
}					t_ant;

void		dissolve_army(t_ant **first_soldier)
{
	t_ant	*first;
	t_ant	*second;

	if (*first_soldier)
	{
		first = *first_soldier;
		while (first)
		{
			second = first;
			first = first->next;
			free(second);
		}
		*first_soldier = NULL;
	}
}


t_ant		*create_army(int number_of_soldiers)
{
	t_ant	*begin

	while (number_of_soldiers)
	{

		--number_of_soldiers;
	}
}
