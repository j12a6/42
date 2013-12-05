/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:45:34 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/05 16:25:21 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (*(s2 + j) == '\0')
		return ((char *)(s1 + j));
	while (*(s1 + i))
	{
		while (*(s1 + i) == *(s2 + j))
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
