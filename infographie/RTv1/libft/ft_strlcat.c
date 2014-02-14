/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:34:11 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 13:57:46 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;

	if (size > ft_strlen(dst))
	{
		i = ft_strlen(dst) + ft_strlen(src);
		ft_strncat(dst, src, (size - ft_strlen(dst) - 1));
	}
	else
		i = size + ft_strlen(src);
	return (i);
}
