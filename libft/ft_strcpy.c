/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:35:12 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/01 22:42:58 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (*(s2 + i))
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	*(s1 + i) = '\0';
	return (s1);
}
