/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:36:34 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/30 11:31:03 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	while (*(s1 + j))
		j++;
	while (*(s2 + i) && (i < n))
	{
		*(s1 + j) = *(s2 + i);
		i++;
		j++;
	}
	*(s1 + j) = '\0';
	return (s1);
}