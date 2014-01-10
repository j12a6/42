/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:18:14 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/10 15:01:05 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (f == NULL || s == NULL)
		return ;
	i = 0;
	while (*(s + i))
	{
		f(i, s + i);
		++i;
	}
}
