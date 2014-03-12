/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:28:57 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/10 13:22:07 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + j))
		++j;
	if ((char)c == '\0')
		return ((char *)(s + j));
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		++i;
	}
	return (NULL);
}
