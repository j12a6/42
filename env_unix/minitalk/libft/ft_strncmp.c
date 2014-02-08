/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:38:28 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 14:00:57 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((*(s1 + i) != *(s2 + i)) || (!(s1 + i) && !(s2 + i)))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}
