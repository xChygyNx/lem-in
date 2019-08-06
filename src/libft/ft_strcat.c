/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:09:11 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/06 11:30:56 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (s1[i] != '\0')
		++i;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		++i;
		++j;
	}
	s1[i] = '\0';
	return (s1);
}
