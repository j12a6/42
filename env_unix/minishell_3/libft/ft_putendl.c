/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:02:23 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/24 08:11:56 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t		ft_putendl(char const *s)
{
	ssize_t		i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)\n", 7));
	i += write(1, s, ft_strlen(s));
	i += ft_putchar('\n');
	return (i);
}
