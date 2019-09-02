/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_vrx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:48:14 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/02 18:02:08 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	in_path(char *name, char **path)
{
	int		i;

	i = -1;
	while (path[++i])
		if (!ft_strcmp(name, path[i]))
			return(1);
	return (0);
}

/*static t_vrx	*add_in(t_vrx *vrx, char **path, t_vrx *all_vrx)
{
	t_vrx		*new;

	new = vrx_copy(vrx);
	new->name = ft_strjoin(vrx->name, "_in");

}*/

static void	add_out(t_vrx *out, char **path)
{
	t_adj	*temp;

	//add_adj with _in with dir = 0
	out->name = ft_strjoin_f(out->name, "_out");
	//free primordial vrx
	temp = out->adj;
	while (temp)
	{
		temp->dir = in_path(temp->name, path) ? -1 : temp->dir;
		temp = temp->next;
	}
}

void    	vrx_in_out(char *vrx_name, char **vrx_path, t_vrx *all_vrx)
{
    t_vrx	*vrx_out;
    t_vrx	*temp;
    
	ft_printf("I'm here\n");
    temp = all_vrx;
    while (ft_strcmp(temp->name, vrx_name))
		temp = temp->next;
	vrx_out = temp;
	while (temp->next)
		temp = temp->next;
	//temp->next = add_in(vrx_out, vrx_path, all_vrx);
	add_out(vrx_out, vrx_path);
	
}