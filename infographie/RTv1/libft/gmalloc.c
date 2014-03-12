/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:29:44 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 16:10:42 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*gmalloc(size_t size)
{
	void	*buf;

	if (!(buf = malloc(size)))
	{
		ft_garb(0, NULL);
		return (NULL);
	}
	if (ft_garb(2, buf) == -1)
	{
		ft_garb(0, NULL);
		return (NULL);
	}
	return (buf);
}
