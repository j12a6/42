/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:23:02 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/19 19:45:07 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_count_wd(char *str, char c)
{
	int		in_word;
	int		n;

	in_word = 0;
	n = 0;
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else
		{
			if (in_word == 0)
				n++;
			in_word = 1;
		}
		str++;
	}
	return (n);
}
