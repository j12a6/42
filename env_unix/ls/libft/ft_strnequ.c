/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:50:40 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/27 15:53:44 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	i = 0;
	if (n == 0)
		return (1);
	while (*s1 && *s2 && *s1 == *s2 && i < n)
	{
		if (i == n - 1)
			return (1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
