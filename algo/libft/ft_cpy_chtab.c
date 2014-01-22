/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_chtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:18:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/21 09:23:59 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_cpy_chtab(char **ch2)
{
	char	**tab;
	int		i;
	int		n;

	i = 0;
	while (ch2[i])
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	n = i;
	i = 0;
	while (i < n)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * ft_strlen(ch2[i]) + 1)))
			return (NULL);
		ft_strcpy(tab[i], ch2[i]);
		++i;
	}
	return (tab);
}
