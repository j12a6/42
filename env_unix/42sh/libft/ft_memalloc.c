/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:35:08 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 13:18:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	if (!(s = (char *)gmalloc(sizeof(*s) * (size + 1))))
		return (NULL);
	s = 0;
	return ((void *)s);
}
