/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:27:12 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 13:02:46 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int		ft_strlenn(char *base)
{
	unsigned int	i;

	i = 0;
	while (*(base + i))
		i++;
	return (i);
}

static char				*ft_toa_next(unsigned int n, char *s, int i, char *base)
{
	int		k;
	int		j;

	k = 0;
	i++;
	j = i;
	while (i > k)
	{
		*(s + i - 1) = base[n % ft_strlenn(base)];
		n = n / ft_strlenn(base);
		i--;
	}
	*(s + j + k) = '\0';
	return (s);
}

char					*ft_toa(unsigned int n, char *base)
{
	char				*s;
	int					i;
	unsigned int		k;

	i = 0;
	k = n;
	if (!(s = (char *)gmalloc(sizeof(*s) * 120)))
		return (NULL);
	if (n == 0)
	{
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}
	while (k > ft_strlenn(base))
	{
		i++;
		k = k / ft_strlenn(base);
	}
	return (ft_toa_next(n, s, i++, base));
}
