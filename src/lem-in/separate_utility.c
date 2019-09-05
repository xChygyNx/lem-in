/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_utility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:56:26 by pcredibl          #+#    #+#             */
/*   Updated: 2019/09/05 15:53:20 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*void	rewrite_adj (t_vrx *vrx, char **path)
{
	t_vrx	*temp_v;
	t_adj	*temp_a;

	temp_v = vrx;
	while (temp_v)
	{
		temp_a = temp_v->adj;
		while (temp_a && ft_strcmp(temp_a->name, name))
			temp_a = temp_a->next;
		if (temp_a)
		{
			ft_printf("name = %s, in path = %d\n", temp_a->name, in_path(temp_v->name, path));
			if (!in_path(temp_v->name, path))
			{
				temp_a->name = ft_strjoin_f(temp_a->name, "_in");
				ft_printf("temp_v = %s, temp_a = %s\n", temp_v->name, temp_a->name);
				ft_printf("-------------------------------------\n");
			}
			else
			{
				ft_printf("temp_v = %s, temp_a = %s\n", temp_v->name, temp_a->name);
				del_adj(temp_v, temp_a->name);
				ft_printf("temp_v = %s, temp_a = %s\n", temp_v->name, temp_a->name);
				ft_printf("-------------------------------------\n");
			}
		}			
		temp_v = temp_v->next;
	}
}*/

//rewrite_adj пришлось переписать
//раньше: вызывалась в цикле для каждой вершины, в списке смежности для каждой вершины находила
//вершину, которую кидали ей как аргумент, и меняла список смежности на вешину
//вершина_in (происходило после изменения начальной вершины на вершину_in).
//сейчас: вызывается 1 раз, сама в цикле ходит по всем вершинам, если и сама вершина, и 
//вершина из списка смежности нажодятся в пути, удаляет ребро из списка смежности
//(будет рисоваться другой специальнообученной функцией), если в пути находится
//только вершина из списка смежности, переписывается в списке смежности на 
//вершину_in (происходит до начала разделения вершин)
void	rewrite_adj (t_vrx *vrx, char **path)
{
	t_vrx	*temp_v;
	t_adj	*temp_a;

	temp_v = vrx;
	while (temp_v)
	{
		temp_a = temp_v->adj;
		while (temp_a)
		{
			if (in_path(temp_a->name, path) && in_path(temp_v->name, path))
				del_adj(temp_v, temp_a->name);
			else if (!ft_strcmp(temp_a->name, path[0]) ||\
				!ft_strcmp(temp_a->name, path[ft_len_arr(path) - 1]))
				;
			else if (in_path(temp_a->name, path))
				temp_a->name = ft_strjoin_f(temp_a->name, "_in");
			temp_a = temp_a->next;
		}			
		temp_v = temp_v->next;
	}
}

void	add_adj_sep (t_vrx *src, char *name, int mode)
{
	char	*adj_name;

	adj_name = mode == IN ? ft_strjoin(name, "_in") :\
		ft_strjoin(name, "_out");
	src->adj = ft_addlst(src->adj, adj_name, 0, 0);
	free(adj_name);
}

t_vrx	*vrx_copy (t_vrx *src, t_vrx *all_vrx)
{
	t_vrx	*copy;

	copy = (t_vrx*)malloc(sizeof(t_vrx));
	copy->x = src->x;
	copy->y = src->y;
	copy->type = src->type;
	copy->visit = src->visit;
	copy->sep = src->sep;
	copy->next = src;
	copy->adj = NULL;
	copy->name = ft_strjoin(src->name, "_in");
	return (copy);
}

int		in_path(char *name, char **path)
{
	int		i;

	i = -1;
	while (path[++i])
		if (!ft_strcmp(name, path[i]))
			return(1);
	return (0);
}

void	path_adj(t_vrx *vrx, char **path)
{
	t_vrx	*temp_v;
	int		i;
	char	*name;
	char	*dst;

	i = 0;
	while (i < ft_len_arr(path) - 1)
	{
		ft_printf("i = %d\n", i);
		name = i == 0 ? path[i] : ft_strjoin(path[i], "_in");
		temp_v = get_vrx(vrx, name);
		dst = i == ft_len_arr(path) - 2 ? path[i + 1] : ft_strjoin(path[i + 1], "_out");
		ft_printf("name = %s, dst = %s\n", name, dst);
		temp_v->adj = ft_addlst(temp_v->adj, dst, -1, ON);
		i++;
	}
}