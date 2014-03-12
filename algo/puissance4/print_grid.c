/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:45:05 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:22:16 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"

void	ft_print_grid(t_all a)
{
	int		i;
	int		j;

	j = 0;
	while (j < a.co)
	{
		i = 0;
		while (i < a.li)
		{
			if (a.grid[i][j] == '.')
				ft_putchar('.');
			else if (a.grid[i][j] == 'X')
				ft_putstr("\033[31mO\033[0m");
			else if (a.grid[i][j] == 'O')
				ft_putstr("\033[33mO\033[0m");
			ft_putstr("  ");
			++i;
		}
		ft_putchar('\n');
		++j;
	}
}
