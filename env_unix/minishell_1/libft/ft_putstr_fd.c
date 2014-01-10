/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:58:45 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 13:41:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t		ft_putstr_fd(char const *s, int fd)
{
	ssize_t		i;

	i = 0;
	i += write(fd, s, ft_strlen(s));
	return (i);
}
