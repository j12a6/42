/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:25:34 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/05 15:49:07 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) > n)
		return (NULL);
	if (*(s2 + j) == '\0')
		return ((char *)(s1 + j));
	while (*(s1 + i))
	{
		while (*(s1 + i) == *(s2 + j) && i < n)
		{
			i++;
			j++;
			if (j == ft_strlen(s2))
				return ((char *)(s1 + i - j));
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
