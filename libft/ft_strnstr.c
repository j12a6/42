/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:25:34 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/27 18:43:12 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	j = 0;
	length = 0;
	while (s2[length])
		length++;
	if (s2[j] == '\0')
		return ((void *)&s1[j]);
	while (s1[i])
	{
		while (s1[i] == s2[j] && i < n)
		{
			i++;
			j++;
			if (j == length)
				return ((void *)&s1[i - j]);
		}
		i = i - j + 1;
		j = 0;
	}
	return ('\0');
}
