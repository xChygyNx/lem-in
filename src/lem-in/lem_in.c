/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/07 12:13:50 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;
	char	*path;

	fd = open("tests/test_from_smight", O_RDONLY);
	lem = create_lem(fd);
//	path = bfs(lem);
	redirect_lem(lem, "end|2|1|start", OFF);
	ft_print_lem_info(lem);
	redirect_lem(lem, "end|2|1|start", ON);
	ft_print_lem_info(lem);
	ft_del_lem(&lem);
	return (0);
}
