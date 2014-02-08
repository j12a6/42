/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_ts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:19:31 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/06 18:23:05 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_copy_ts(char **ts)
{
	char	**tab;
	int		i;

	i = 0;
	while (ts[i] && ts[i][0])
		i++;
	if (!(tab = (char **)gmalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (ts[i] && ts[i][0])
	{
		if (!(tab[i] = (char *)gmalloc(sizeof(char)
										* (ft_strlen(ts[i]) + 1))))
			return (NULL);
		ft_strcpy(tab[i], ts[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
