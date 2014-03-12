/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:30:08 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/12 19:24:26 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		k;

	neg = 1;
	k = 0;
	while ((char)ft_isspace(*str))
		++str;
	if ((str[0] == '-' && str[1] == '+') || (str[0] == '+' && str[1] == '-'))
		return (0);
	if (*str == '-')
	{
		neg = -1;
		++str;
	}
	if (*str == '+')
		++str;
	while (*str <= '9' && *str >= '0')
	{
		k = *str - '0' + k * 10;
		++str;
	}
	return (k * neg);
}
