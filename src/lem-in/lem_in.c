/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/30 21:06:09 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;

	lem = create_lem(0);
//	ft_printf("%s", lem->map);
	ft_print_lem_info(lem);
	change_dir(lem, "end", "3");
	ft_print_lem_info(lem);
	dijkstra(lem);
	ft_del_lem(&lem);
	return (0);
}
