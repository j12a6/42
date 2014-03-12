/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:42:52 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/30 18:05:50 by makoudad         ###   ########.fr       */
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
		i++;
	}
}
