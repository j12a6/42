/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_size_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 10:48:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/23 08:22:48 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_size_p(char *str)
{
	int		i;
	int		size_of_word;

	i = 0;
	while (*(str + i) && ft_isspace(*(str + i)) == 1)
		++i;
	size_of_word = 0;
	while (*(str + i) && !ft_isspace(*(str + i)))
	{
		++i;
		++size_of_word;
	}
	return (size_of_word);
}
