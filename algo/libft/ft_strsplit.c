/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:07:41 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 17:24:57 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	**ft_strsplit(char *s, char c)
{
	char	**tab;
	int		i;
	int		k;
	int		nb_word;
	int		size;

	if (s == NULL)
		return (NULL);
	nb_word = ft_count_word(s, c);
	if (!(tab = (char **)gmalloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (k < nb_word)
	{
		while (*(s + i) && *(s + i) == c)
			++i;
		size = ft_word_size(s + i, c);
		if (!(tab[k] = (char *)gmalloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_strncpy(tab[k], s + i, size);
		tab[k][size] = '\0';
		i += size;
		++k;
	}
	tab[k] = NULL;
	return (tab);
}
