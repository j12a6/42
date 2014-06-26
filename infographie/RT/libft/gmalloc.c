/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:34:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 21:27:25 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*gmalloc(size_t size)
{
	void	*s;

	if (!(s = malloc(size * 10000)))
	{
		ft_putendl_fd("Problem malloc: not enough space", 2);
		return (NULL);
	}
	if (!(ft_list_mal(1, s)))
		return (NULL);
	return (s);
}
