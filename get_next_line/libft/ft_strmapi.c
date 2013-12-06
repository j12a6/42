/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:28:20 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/26 12:19:42 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * (400 + 1));
	if (str == NULL || f == NULL)
		return (NULL);
	while (s[i])
	{
	str[i] = f(i, s[i]);
	i++;
	}
	return (str);
}
