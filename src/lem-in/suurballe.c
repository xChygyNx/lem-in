/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/12 23:09:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

/*static void	paths_copy(char **src, char **dst, t_lem *lem)
{
	int		i;
	size_t	len;

	i = 0;
	while (src[i])
	{
		len = ft_strlen(src[i]);
		if (!(dst[i] = ft_strnew(len)))
			ft_exit(&lem, MALLOC_FAILURE);
		dst[i] = ft_strcpy(src[i]);

	}
}

static int	count_path(char **paths)
{
	int		i;

	i = 0;
	while (paths && paths[i])
		i++;
	return (i);
}

static void	add_path(t_lem *lem, char *path)
{
	int		count;
	char	**new_paths;

	count = count_path(lem->path);
	if (!(new_paths = (char**)malloc(sizeof(char*) * (count + 2))))
		ft_exit(&lem, MALLOC_FAILURE);
	paths_copy(lem->path, new_paths, lem);
	free_tab(lem->path);
	lem->path = new_paths;
}*/

void		suurballe(t_lem *lem)
{
	char	*path;
	int		i;
	t_bfs	*bfs_src;

	bfs_src = NULL;
	//ПЕРВЫЙ ПРОХОД
	//вызываем поиск в ширину, и ищем пути пока они есть
	while ((path = bfs(lem, &bfs_src)))
	{
		ft_printf("path#1 = %s\n", path);
		//находим наикратчайший путь
		//удаляем направление пути, а обратное делаем с весом -1
		redirect_lem(lem, path, OFF);
		//если после удаления ребра у нас получается несвязный граф
//		ft_print_lem_info(lem);
		if (!dfs(lem, lem->vrx->name))
		{
			//восстанавливаем текущий путь и выходим из цикла
			redirect_lem(lem, path, ON);
			break ;
		}
		unvisit(lem->vrx);
		free(path);
	}

	//восстанавливаем наш граф (weight = 1 и dir = 1),
	//кроме тех ребер в коротрых отключены оба направления
	unvisit(lem->vrx);
	renovation_one_to_two_dir(lem);
	//ВТОРОЙ ПРОХОД
	//у нас получился граф с исключенными ребрами найденными в разных BFS
	//вызываем поиск в ширину, и ищем пути пока они есть
	i = 0;
	///!!bfs_src после первого прохода NULL
	while ((path = bfs(lem, &bfs_src)))
	{
		ft_printf("path#2 = %s\n", path);
		redirect_lem(lem, path, OFF);
		//если длина пути больше количества муравьев,
		//то не имеет смысла дальше искать пути (!ТРЕБУЕТ ПРОВЕРКИ!)
		if (i && ft_char_count(path, '|') + 1 > lem->ant_c)
		{
			free(path);
			break ;
		}
		//добавляем в структуру очередной путь
		if (!(lem->path = add_path(lem, lem->path, path)))
			ft_exit(&lem, MALLOC_FAILURE);
		free(path);
		++i;
	}
	//восставналиваем полностью граф
	full_renovation_lem(lem);
	free_bfs(&bfs_src);
	//после выполнения этой функции в струтуру lem
	//должно записаться N количество путей в зависимости от количества муравьев
}

//Алгоритм подсчета общего количества шагов по комнатам.
//честно своровано у widraugr
//https://paper.dropbox.com/doc/Lem_in-YtlG6nyxq5eqVZ8Go9djz
//z = (a + (x - w))/w (округлить в большую сторону)
//x - колличество муравьев.
//a - суммарное количество шагов по всем путям.
//w - колличество путей.
int		count_steps(t_lem *lem)
{
	t_listpath	*path_t;
	int			a;
	int			w;
	int			z;

	a = 0;
	w = 0;
	path_t = lem->path;
	while (path_t)
	{
		a += (path_t->path_len - 1);
		path_t = path_t->next;
		w++;
	}
	if (!((a + (lem->ant_c - w)) % w))
		z = (a + (lem->ant_c - w)) / w;
	else
		z = (a + (lem->ant_c - w)) / w + 1;
	return (z);
}
