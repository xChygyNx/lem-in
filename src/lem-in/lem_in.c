/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:32:17 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/30 14:35:46 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char **av)
{
	t_lem	*lem;
	t_ant	*army;

	lem = create_lem(0);
	army = create_army(lem->ant_c);
	ac == 2 && !ft_strcmp(av[1], "-wm") ? 0: ft_printf("%s\n", lem->map);
	find_optimal_path(lem, &army);
	ft_del_lem(&lem);
	return (0);
}
