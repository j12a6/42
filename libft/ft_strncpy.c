/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 20:27:55 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/01 22:45:23 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;

	if (n == 0)
		return (NULL);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (*(s2 + i) && (i < n))
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	while (i < n)
	{
		*(s1 + i) = '\0';
		i++;
	}
	return (s1);
}
