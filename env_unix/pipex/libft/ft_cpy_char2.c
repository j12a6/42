/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_char2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:18:51 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/29 21:21:40 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	**ft_cpy_char2(char **ch2)
{
	char	**tab;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (ch2[i])
		i++;
	if (!(tab = (char **)malloc(sizeof(**tab) * i + 10000)))
		return (NULL);
	n = i;
	i = 0;
	while (i < n)
	{
		if (!(tab[i] = (char *)malloc(sizeof(*tab[i])
			* ft_strlen(ch2[i]) + 10000)))
			return (NULL);
		ft_strcpy(tab[i], ch2[i]);
		i++;
	}
	return (tab);
}
