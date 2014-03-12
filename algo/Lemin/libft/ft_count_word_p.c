/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:14:36 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/23 21:06:00 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_count_word_p(char *str)
{
	int		in_word;
	int		n;

	in_word = 0;
	n = 0;
	while (*str)
	{
		if (ft_isspace(*str) == 1)
			in_word = 0;
		else if (!ft_isspace(*str) && in_word == 0)
		{
			++n;
			in_word = 1;
		}
		++str;
	}
	return (n);
}
