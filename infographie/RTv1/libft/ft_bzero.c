/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:17:28 by makoudad          #+#    #+#             */
/*   Updated: 2013/11/30 11:36:14 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	if (n == 0)
		return ;
	while (n--)
		*(b + n) = '\0';
}
