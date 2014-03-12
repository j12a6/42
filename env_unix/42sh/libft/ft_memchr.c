/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:28:37 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/01 15:03:14 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)s;
	while (n--)
	{
		if (*d != (unsigned char)c)
			d++;
		else
			return ((void *)d);
	}
	return (NULL);
}
