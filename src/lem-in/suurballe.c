/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurballe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:36 by astripeb          #+#    #+#             */
/*   Updated: 2019/09/10 00:30:36 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

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
		ft_printf("path = %s\n", path);
		//находим наикратчайший путь
		//удаляем направление пути, а обратное делаем с весом -1
		redirect_lem(lem, path, OFF);
		//если после удаления ребра у нас получается несвязный граф
		if (!dfs(lem, lem->vrx->name))
		{
			//восстанавливаем текущий путь и выходим из цикла
			redirect_lem(lem, path, ON);
			break ;
		}
		//если длина пути больше количества муравьев,
		//то не имеет смысла дальше искать пути (!ТРЕБУЕТ ПРОВЕРКИ!)
		if (ft_char_count(path, '|') + 1 > lem->ant_c)
		{
			free(path);
			break ;
		}
		unvisit(lem->vrx);
		free(path);
	}
	//восстанавливаем наш граф (weight = 1 и dir = 1),
	//кроме тех ребер в коротрых отключены оба направления
	renovation_one_to_two_dir(lem);

	//ВТОРОЙ ПРОХОД
	//у нас получился граф с исключенными ребрами найденными в разных BFS
	//вызываем поиск в ширину, и ищем пути пока они есть
	i = 0;
	while ((path = bfs(lem, &bfs_src)))
	{
		//если длина пути больше количества муравьев,
		//то не имеет смысла дальше искать пути (!ТРЕБУЕТ ПРОВЕРКИ!)
		if (!i && ft_char_count(path, '|') + 1 > lem->ant_c)
		{
			free(path);
			break ;
		}
		//добавляем в структуру очередной путь
		if (!(lem->path = add_path(lem->path, path)))
			ft_exit(&lem, MALLOC_FAILURE);
		free(path);
		++i;
	}
	//восставналиваем полностью граф
	full_renovation_lem(lem);
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
	t_path	*path_t;
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
