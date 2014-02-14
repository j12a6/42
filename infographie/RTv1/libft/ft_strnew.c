/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:03:46 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 12:59:42 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*s;
	size_t		i;

	i = 0;
	if (!(s = (char *)gmalloc(sizeof(*s) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		*(s + i) = '\0';
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
