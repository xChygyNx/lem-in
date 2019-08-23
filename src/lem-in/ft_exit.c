/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <astripeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:39:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/08/23 20:04:46 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		ft_exit(t_rooms **rooms, int err)
{
	ft_free_rooms(rooms);
	if (err == INVALID_INPUT)
		ft_fprintf(2, "Error: Invalid map\n");
	else
		perror("Error: ");
	exit(err);
}
