/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:04:35 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/27 18:21:25 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (p1 > p2)
	{
		p1 = p1 + (unsigned char)n - 1;
		p2 = p2 + (unsigned char)n - 1;
		while (n--)
			*p1-- = *p2--;
	}
	else
	{
		while (n--)
			*p1++ = *p2++;
	}
	return (s1);
}
