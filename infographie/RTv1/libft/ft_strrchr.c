/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:18:40 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 14:03:17 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s) - 1;
	if ((char)c == '\0')
		return ((char *)(s + i + 1));
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
