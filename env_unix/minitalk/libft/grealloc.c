/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grealloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 14:42:11 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/31 09:35:51 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*grealloc(char *old, size_t size)
{
	char	*new;

	if (!(new = gmalloc(size)))
		return (NULL);
	new = ft_strcpy(new, old);
	gfree(old);
	return (new);
}
