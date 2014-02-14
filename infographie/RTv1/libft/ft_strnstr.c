/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:28:34 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 14:03:05 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (ft_strlen(s2) > n)
		return (NULL);
	if (*(s2 + i) == '\0')
		return ((char *)(s1 + i));
	while (*(s1 + i))
	{
		while (*(s1 + i) == *(s2 + j) && (i < n))
		{
			i++;
			j++;
			if (j == ft_strlen(s2) || (j == n))
				return ((char *)(s1 + i - j));
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
