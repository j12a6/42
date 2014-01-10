/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:02:23 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 13:37:08 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t		ft_putendl(char const *s)
{
	ssize_t		i;

	i = 0;
	i += write(1, s, ft_strlen(s));
	i += ft_putchar('\n');
	return (i);
}
