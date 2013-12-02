/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:10:02 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/27 18:38:02 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size > ft_strlen(dst))
	{
		i = ft_strlen(dst) + ft_strlen(src);
		ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
	}
	else
		i = size + ft_strlen(src);
	return (i);
}
