/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:56:05 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/31 09:46:43 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s == NULL)
	{
		ft_putstr("(null)");
		ft_putchar('\n');
		return ;
	}
	ft_putstr(s);
	ft_putchar('\n');
}
