/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lem2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:48:04 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/10 15:04:48 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_edge(t_rooms *lem, char **line)
{
	char	**vertexes;

	lem += 0;
	while (*line)
	{
		vertexes = ft_strsplit(*line, '-');
		size_arr(vertexes);
		exist_vertex(vertexes, lem);
		get_next_line(0, line);
	}
}