/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:24:04 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 13:35:12 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"

ssize_t		ft_putnbr(int n)
{
	ssize_t		i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		i++;
		ft_putchar('-');
		n *= -1;
	}
	if (n <= 9)
	{
		i += ft_putchar(n % 10 + '0');
		return (i);
	}
	else
	{
		i += ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (i + 1);
}
