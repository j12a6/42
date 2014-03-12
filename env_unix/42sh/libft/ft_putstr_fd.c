/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:40:06 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/31 09:51:53 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return ;
	}
	i = 0;
	while (*(s + i) != '\0')
	{
		ft_putchar_fd(*(s + i), fd);
		i++;
	}
}
