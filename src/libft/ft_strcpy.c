/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:23:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/08/12 17:36:33 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	//printf("src = %s\n", src);
	while (src[i] != '\0')
	{
	//	printf("i = %zu, src = %c\n", i, src[i]);
		//printf("dest = %c\n", dest[i]);
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
