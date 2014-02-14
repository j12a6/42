/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:58:38 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/01 11:50:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	if (n == 0)
		return (1);
	while (*(s1 + i) && *(s2 + i) && (i < n))
	{
		if (*(s1 + i) != *(s2 + i))
			return (0);
		i++;
		if ((*(s1 + i) && *(s2 + i) == '\0' && i < n)
			|| (*(s1 + i) == '\0' && *(s2 + i) && i < n))
			return (0);
	}
	return (1);
}
