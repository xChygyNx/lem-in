/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/27 19:38:02 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	t_rooms	*room;
	int		fd;

	fd = open("./tests/bad_test02", O_RDONLY);
	lem = create_lem(fd);
//	ft_printf("%s", lem->map);
	ft_print_lem_info(lem);
	ft_del_lem(&lem);
	return (0);
}
