/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:28:34 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/01 14:55:12 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = 0;
	while (*(s2 + length))
		length++;
	if (*(s2 + j) == '\0')
		return ((char *)(s1 + i));
	while (*(s1 + i))
	{
		while (*(s1 + i) == *(s2 + j))
		{
			i++;
			j++;
			if (j == length)
				return ((char *)(s1 + i - j));
		}
		i = i - j + 1;
		j = 0;
	}
	return (NULL);
}
