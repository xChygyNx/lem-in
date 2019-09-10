/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/11 00:55:03 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
	int		fd;

	fd = open("tests/spherical_test_in_vacuum", O_RDONLY);
	lem = create_lem(fd);
	suurballe(lem);
	ft_print_paths(lem->path);
//	ft_print_lem_info(lem);
	ft_del_lem(&lem);
	return (0);
}
