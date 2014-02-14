/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:42:15 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 13:57:13 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	if (!(s2 = (char *)gmalloc(sizeof(*s2) * (ft_strlen(s) + 1))))
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(s2 + i) = f(i, *(s + i));
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
