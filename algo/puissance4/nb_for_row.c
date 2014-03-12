/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_for_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 17:54:05 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:21:58 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	ft_space_for_row4(t_all a, int start, int end, t_s s)
{
	int		nb;

	nb = 1;
	while (start <= end)
	{
		if (a.grid[start][a.j] == s.symb2)
			return (1);
		else if (a.grid[start][a.j] == s.symb1)
			++nb;
		++start;
	}
	return (nb);
}

int			ft_find_nb_for_row(t_all a, t_s s)
{
	int		start;
	int		end;
	int		max;
	int		nb;

	max = 0;
	nb = 1;
	start = (a.i - 3 < 0 ? 0 : a.i - 3);
	while (a.i - start >= 0)
	{
		end = (start + 3 < a.li ? start + 3 : a.li - 1);
		if (end - start < 3)
			nb = 1;
		else
			nb = ft_space_for_row4(a, start, end, s);
		if (nb > max)
			max = nb;
		++start;
	}
	return (max);
}
