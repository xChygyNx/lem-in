/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/02 17:17:28 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;
	char	*path;

	fd = open("tests/test_direction", O_RDONLY);
	lem = create_lem(fd);
	path = dijkstra(lem);
	ft_printf("path = %s", path);
	free(path);
	redirect_lem(lem, path);
	unvisit(lem->vrx);
	ft_print_lem_info(lem);
	ft_del_lem(&lem);
	return (0);
}
