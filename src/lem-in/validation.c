/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:35:59 by astripeb          #+#    #+#             */
/*   Updated: 2019/08/25 18:30:40 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_validate_room(char **map)
{
	int i;

	if (ft_len_arr(map) != 3)
		return (0);
	i = 1;
	while (map[i])
	{
		if (!ft_isdigitstr(map[i]) ||\
		ft_int_len(ft_atoi(map[i])) != ft_strlen(map[i]))
		{
			ft_free_arr(map);
			return (0);
		}
		++i;
	}
	return (1);
}
