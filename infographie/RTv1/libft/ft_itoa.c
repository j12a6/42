/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:27:12 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 13:08:03 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_itoa_next(int n, char *s, int i)
{
	int		k;
	int		j;

	k = 0;
	i++;
	if (n < 0)
	{
		*s = '-';
		n *= -1;
		k = 1;
		i++;
	}
	j = i;
	while (i > k)
	{
		*(s + i - 1) = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	*(s + j + k) = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		k;

	i = 0;
	k = n;
	if (!(s = (char *)gmalloc(sizeof(*s) * 12)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n == 0)
	{
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}
	while ((k > 9) || (k < -9))
	{
		i++;
		k = k / 10;
	}
	return (ft_itoa_next(n, s, i++));
}
