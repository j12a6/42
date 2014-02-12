/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ts_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:18:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/01 12:06:51 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	**ft_ts_copy(char **ts)
{
	char	**new;
	int		i;
	int		n;

	i = 0;
	while (ts[i])
		i++;
	n = i;
	if (!(new = (char **)gmalloc(sizeof(char *) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (!(new[i] = (char *)gmalloc(sizeof(char) * ft_strlen(ts[i]) + 1)))
			return (NULL);
		ft_strcpy(new[i], ts[i]);
		++i;
	}
	new[n] = NULL;
	return (new);
}
