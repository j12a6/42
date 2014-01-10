/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:30:08 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/01 17:50:20 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int		neg;
	int		k;

	if (str == NULL)
		return (0);
	neg = 1;
	k = 0;
	while (*str && (char)ft_isspace(*str))
		str++;
	if ((str[0] == '-' && str[1] == '+') || (str[0] == '+' && str[1] == '-'))
		return (0);
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str && *str <= '9' && *str >= '0')
	{
		k = *str - '0' + k * 10;
		str++;
	}
	return (k * neg);
}
