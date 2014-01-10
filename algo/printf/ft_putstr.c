/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:58:45 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/19 10:08:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

ssize_t		ft_putstr(char const *s)
{
	size_t		lenght;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	lenght = ft_strlen(s);
	write(1, s, lenght);
	return ((ssize_t)lenght) ;
}
