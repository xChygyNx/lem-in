/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:10:06 by pcredibl          #+#    #+#             */
/*   Updated: 2019/10/22 19:18:41 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_flags(char **argv, t_lem *lem)
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-wm"))
			lem->without_map = 1;
		else if (!ft_strcmp(argv[i], "-v"))
			lem->visualization = 1;
		else if (!ft_strcmp(argv[i], "-d"))
			lem->design_map = 1;
		else 
			ft_exit(&lem, USAGE);
	}
}