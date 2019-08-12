/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:09:56 by pcredibl          #+#    #+#             */
/*   Updated: 2019/08/12 18:47:26 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char	**add_elem(char **tab, char *elem)
{
	char	**temp;
	size_t	size_arr;

	size_arr = 1;
	ft_printf("tab = %p\n", tab);
	ft_printf("*tab = %p\n", *tab);
	while (tab[size_arr - 1])
		size_arr++;
	temp = (char**)malloc(sizeof(char*) * (size_arr + 1));
	temp[size_arr] = "\0";
	size_arr = 0;
	while (tab[size_arr])
	{
		//temp[size_arr] = (char*)malloc(sizeof(char) * (ft_strlen(tab[size_arr]) + 1));
		//temp[size_arr] = ft_strcpy(temp[size_arr], tab[size_arr]);
		size_arr++;
	}
	temp[size_arr] = (char*)malloc(sizeof(char) * (ft_strlen(elem) + 1));
	temp[size_arr] = ft_strcpy(temp[size_arr], elem);
	return(temp);
}