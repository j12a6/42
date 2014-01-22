/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:23:11 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 16:49:49 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;

	if (!(str = (unsigned char *)gmalloc(sizeof(*str) * size + 1)))
		return (NULL);
	while (size--)
		str[size] = '\0';
	return ((void *)str);
}
