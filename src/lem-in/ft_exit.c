/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 18:39:28 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/14 13:55:07 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_exit(t_lem **lem, int err)
{
	ft_del_lem(lem);
	if (err == INVALID_INPUT)
		ft_fprintf(2, "Error: Invalid map\n");
	else if (err == START_END)
		ft_fprintf(2, "Error: Two starts/ends, or not start/end\n");
	else if (err == DOUBLE_VRX)
		ft_fprintf(2, "Error: Duplicate vertex or same coordinates\n");
	else if (err == ONE_COMPONENT)
		ft_fprintf(2, "Error: Start & end situated in different \
connected components\n");
	else if (err == WROTE_ANTS)
		ft_fprintf(2, "Error: wrong count of ants\n");
	else
		perror("Error: ");
	exit(err);
}
