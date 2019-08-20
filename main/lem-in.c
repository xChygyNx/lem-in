/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/20 21:32:06 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_rooms	*lem;
	int		fd;

	fd = open("test", O_RDONLY);
	lem = create_lem(fd);
	while (lem)
	{
		ft_printf("name = %s, x = %d, y = %d, type = %d, visit = %d\n", lem->name, lem->x, lem->y, lem->type, lem->visit);
		while (lem->adj)
		{
			ft_printf("adj = %s\n", lem->adj->name);
			lem->adj = lem->adj->next;
		}
		lem = lem->next;
	}
	return (0);
}