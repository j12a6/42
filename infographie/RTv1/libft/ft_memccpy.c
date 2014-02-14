/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:43:46 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/01 15:16:57 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*s3;
	unsigned char		*s4;
	size_t				i;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (i < n)
	{
		*(s3 + i) = *(s4 + i);
		if (*(s4 + i) == (unsigned char)c)
			return (s3 + 1 + i);
		i++;
	}
	return (NULL);
}
