/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 10:40:36 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/31 08:44:02 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		**ft_strparse(char *str)
{
	char	**tab;
	int		n;
	int		nb_word;
	int		word_size;

	if (str == NULL)
		return (NULL);
	nb_word = ft_count_word_p(str);
	if (!(tab = (char **)gmalloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	n = 0;
	while (n < nb_word)
	{
		word_size = ft_word_size_p(str);
		if (!(tab[n] = (char *)gmalloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		while (*str && ft_isspace(*str) == 1)
			++str;
		ft_strncpy(tab[n], str, word_size);
		str += word_size;
		++n;
	}
	tab[n] = NULL;
	return (tab);
}
