/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:58:45 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 13:40:43 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t		ft_putstr(char const *s)
{
	ssize_t		i;

	i = 0;
	if (s == NULL)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	i += write(1, s, ft_strlen(s));
	return (i);
}
