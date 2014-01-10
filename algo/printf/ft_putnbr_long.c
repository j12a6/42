/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:24:04 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/19 10:33:13 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

ssize_t		ft_putnbr_long(unsigned int n)
{
	ssize_t		i;

	i = 0;
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		i += ft_putnbr_long(n / 10);
		ft_putchar(n % 10 + '0');
	}
	return (i + 1);
}
