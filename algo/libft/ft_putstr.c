/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:58:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 17:07:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t		ft_putstr(char const *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
