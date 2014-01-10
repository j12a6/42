/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:33:15 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/29 14:58:09 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*b;
	unsigned char	*d;

	b = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (n--)
		*b++ = *d++;
	return (s1);
}
