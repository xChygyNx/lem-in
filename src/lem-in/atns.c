/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:26:10 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/14 14:02:15 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

typedef struct		s_ant
{
	int				serial_number;
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

void		first_soldier_commission(t_ant **army)
{
	t_ant *old_soldier;

	if (*army)
	{
		old_soldier = *army;
		*army = old_soldier->next;
		free(old_soldier);
	}
}

void		soldiers_commission(t_ant **army)
{
	t_ant	*first;
	t_ant	*second;
	t_ant	*temp;

	if (*army)
	{
		first = *army;
		while (first && first->path->vrx->type == END)
			first_soldier_commission(&first);
		*army = first;
		while (first)
		{
			second = first;
			first = first->next;
			if (first && first->path->vrx->type == END)
			{
				temp = first;
				first = first->next;
				second = first;
				free(temp);
			}
		}
	}
}

t_ant		*new_soldier(int serial_number)
{
	t_ant	*soldier;

	if (!(soldier = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	soldier->serial_number = serial_number;
	soldier->path = NULL;
	soldier->next = NULL;
	return (soldier);
}

t_ant		*create_army(int number_of_soldiers)
{
	int		serial_number;
	t_ant	*army;
	t_ant	*soldier;

	serial_number = 1;
	if (!(army = new_soldier(serial_number)))
		return (NULL);
	soldier = army;
	serial_number += 1;
	while (serial_number <= number_of_soldiers)
	{
		if (!(soldier->next = new_soldier(serial_number)))
		{
			dissolve_army(&army);
			return (NULL);
		}
		soldier = soldier->next;
		++serial_number;
	}
	return (army);
}
