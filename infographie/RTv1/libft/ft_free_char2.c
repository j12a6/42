/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 11:00:43 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/24 12:43:54 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_free_char2(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		gfree((void *)s[i]);
		++i;
	}
	gfree((void *)s);
	return (0);
}
