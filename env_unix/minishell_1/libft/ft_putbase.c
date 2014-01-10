/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 11:17:05 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 13:09:50 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

ssize_t			ft_putbase(unsigned int n, char *base)
{
	ssize_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(base);
	if (n <= len)
	{
		i += ft_putchar(*(base + n % len));
		return (i);
	}
	else
	{
		i += ft_putbase(n / len, base);
		ft_putchar(*(base + n % len));
	}
	return (i + 1);
}
