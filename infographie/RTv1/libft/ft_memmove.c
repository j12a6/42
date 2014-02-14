/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:03:58 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/27 18:17:31 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char		*s3;
	unsigned char		*s4;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	if (s4 < s3)
	{
		s4 = s4 + n - 1;
		s3 = s3 + n - 1;
		while (n--)
			*s3-- = *s4--;
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
