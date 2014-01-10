/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:24:04 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 13:35:13 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"

ssize_t		ft_putnbr_fd(int n, int fd)
{
	ssize_t		i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(fd, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n <= 9)
	{
		i += ft_putchar_fd(n + '0', fd);
		return (i);
	}
	else
	{
		i += ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	return (i + 1);
}
