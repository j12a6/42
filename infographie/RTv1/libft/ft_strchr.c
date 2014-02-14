/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:20:40 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/01 15:15:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + j))
		j++;
	if ((char)c == '\0')
		return ((char *)(s + j));
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
