/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:23:11 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/29 12:07:14 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (size--)
	{
		str[size] = '\0';
	}
	return ((void *)str);
}
