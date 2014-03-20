/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:45:34 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/20 16:16:53 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	size_t		len;

	if (*s2 == '\0')
		return ((char *)(s1));
	i = 0;
	len = ft_strlen(s2);
	while (*(s1 + i))
	{
		j = 0;
		while (*(s1 + i) == *(s2 + j))
		{
			++i;
			++j;
			if (j == len)
				return ((char *)(s1 + i - j));
		}
		i = i - j + 1;
	}
	return (NULL);
}
