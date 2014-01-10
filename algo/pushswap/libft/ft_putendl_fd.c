/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:26:45 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 13:42:13 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

ssize_t		ft_putendl_fd(char const *s, int fd)
{
	ssize_t		i;

	i = 0;
	i += write(fd, s, ft_strlen(s));
	i += ft_putchar_fd('\n', fd);
	return (i);
}
