/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:30:34 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/01 21:41:54 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
		i++;
	i--;
	if ((char)c == '\0')
		return ((void *)(s + i + 1));
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((void *)(s + i));
		i--;
	}
	return ('\0');
}
