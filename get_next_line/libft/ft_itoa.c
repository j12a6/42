/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:36:37 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/06 14:53:16 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char		*ft_cpy_itoa(char *str, int c, int i, int neg)
{
	int		k;

	k = 10;
	if (c < 0)
	{
		str[0] = '-';
		c = c * (-1);
	}
	*(str + i + neg) = '\0';
	while (i > 0)
	{
		*(str + i + neg - 1) = c % k + '0';
		c = c / 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int c)
{
	int		i;
	int		neg;
	char	*str;

	neg = 0;
	if (c < 0)
		neg = 1;
	i = ft_count_digit(c);
	str = (char *)malloc(sizeof(*str) * ((i + neg + 1)));
	if (str == NULL)
		return (NULL);
	if (c == -2147483648)
		ft_strcpy(str, "-2147483648");
	else
		ft_cpy_itoa(str, c, i, neg);
	return (str);
}
