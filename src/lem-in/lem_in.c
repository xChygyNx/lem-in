/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/07 17:11:44 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;
	char	*path;
	t_bfs	*bfs_src;

	fd = open("tests/spherical_test_in_vacuum", O_RDONLY);
	lem = create_lem(fd);
	bfs_src = NULL;
	path = bfs(lem, &bfs_src);;
	ft_printf("path = %s\n", path);
//	redirect_lem(lem, path, OFF);
	ft_print_lem_info(lem);
//	redirect_lem(lem, "end|2|1|start", ON);
//	ft_print_lem_info(lem);
	ft_del_lem(&lem);
	return (0);
}
