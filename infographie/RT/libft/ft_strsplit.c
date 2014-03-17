/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:07:41 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/31 08:44:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	**ft_strsplit(char *s, char c)
{
	char	**tab;
	int		n;
	int		nb_word;
	int		word_size;

	if (s == NULL)
		return (NULL);
	nb_word = ft_count_word(s, c);
	if (!(tab = (char **)gmalloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	n = 0;
	while (n < nb_word)
	{
		word_size = ft_word_size(s, c);
		if (!(tab[n] = (char *)gmalloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		while (*s && *s == c)
			++s;
		ft_strncpy(tab[n], s, word_size);
		s += word_size;
		++n;
	}
	tab[n] = NULL;
	return (tab);
}
