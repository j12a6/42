/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_for_column.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 18:42:54 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:20:35 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_find_nb_for_column(t_all a, t_s s)
{
	int		end;
	int		k;
	int		nb;

	nb = 1;
	end = (a.j + 3 < a.co ? a.j + 3 : a.co - 1);
	k = a.j;
	while (k <= end)
	{
		if (a.grid[a.i][k] == s.symb2)
			break ;
		if (a.grid[a.i][k] == s.symb1)
			++nb;
		++k;
	}
	return (nb);
}
