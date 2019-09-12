/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/12 19:41:55 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_lem	*lem;
//	int		fd;

//	fd = open("tests/test_from_smight", O_RDONLY);
	lem = create_lem(0);
	suurballe(lem);
	ft_print_paths(lem->path);
//	ft_print_lem_info(lem);
	ft_del_lem(&lem);
	return (0);
}
