/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:02:35 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/27 20:17:51 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s2;
	size_t		i;

	if (s == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	i = 0;
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		*(s2 + i) = *(s + start);
		i++;
		start++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
