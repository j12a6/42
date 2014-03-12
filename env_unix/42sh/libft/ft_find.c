/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:57:00 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 15:36:47 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_find(char *s1, char *s2)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(s2);
	while (*(s1 + i))
	{
		if (ft_strncmp(s1 + i, s2, size) == 0)
			++j;
		++i;
	}
	return (j);
}
