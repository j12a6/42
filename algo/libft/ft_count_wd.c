/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 15:14:36 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/10 15:26:32 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_count_wd(char *str, char c)
{
	int		in_word;
	int		n;

	if (str == NULL)
		return (-1);
	in_word = 0;
	n = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else
		{
			if (in_word == 0)
				++n;
			in_word = 1;
		}
		++str;
	}
	return (n);
}
