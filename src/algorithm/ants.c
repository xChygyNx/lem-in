/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:26:10 by astripeb          #+#    #+#             */
/*   Updated: 2019/10/26 17:37:11 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			first = first->prev;
			free(second);
		}
		*first_soldier = NULL;
	}
}

void		first_soldier_commission(t_ant **army)
{
	t_ant	*old_soldier;

	if (*army)
	{
		old_soldier = *army;
		*army = old_soldier->next;
		*army ? (*army)->prev = NULL : 0;
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
			if (first->path->vrx->type == END)
			{
				temp = first;
				first = first->next;
				first ? first->prev = NULL : 0;
				second->next = first;
				free(temp);
				continue ;
			}
			second = first;
			first = first->next;
		}
	}
}

t_ant		*new_soldier(int serial_number, char style)
{
	t_ant	*soldier;

	if (!(soldier = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	soldier->serial_number = serial_number;
	soldier->path = NULL;
	soldier->next = NULL;
	soldier->prev = NULL;
	soldier->color.t_rgb.red = red_spectrum (style);
	soldier->color.t_rgb.green = green_spectrum (style);
	soldier->color.t_rgb.blue = blue_spectrum (style);
	return (soldier);
}

t_ant		*create_army(int number_of_soldiers)
{
	t_ant	*army;
	t_ant	*soldier;
	int		color;

	if (!(army = new_soldier(number_of_soldiers)))
		return (NULL);
	army ? army->next = NULL : 0;
	soldier = army;
	number_of_soldiers--;
	color = 0;
	while (number_of_soldiers)
	{
		if (!(soldier->prev = new_soldier(number_of_soldiers, color++ % 10)))
		{
			dissolve_army(&army);
			return (NULL);
		}
		soldier->prev->next = soldier;
		soldier = soldier->prev;
		number_of_soldiers--;
	}
	return (army);
}
