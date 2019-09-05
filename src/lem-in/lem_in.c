/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/05 11:01:52 by pcredibl         ###   ########.fr       */
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
//	ft_print_lem_info(lem);
	redirect_lem(lem, path);
	free(path);
	unvisit(lem->vrx);
	ft_print_lem_info(lem);
	ft_del_lem(&lem);
	return (0);
}
