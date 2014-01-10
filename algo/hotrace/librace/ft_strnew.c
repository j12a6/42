/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:03:46 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/27 20:26:44 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char		*s;
	size_t		i;

	i = 0;
	s = (char *)malloc(sizeof(*s) * (size + 1));
	if (s == NULL)
		return (NULL);
	while (i < size)
	{
		*(s + i) = '\0';
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
