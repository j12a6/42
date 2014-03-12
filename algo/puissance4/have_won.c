/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_won.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 21:12:47 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:23:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"

static int	ft_won_2(t_all a, t_s *me, t_s *you)
{
	ft_reset_save_board(&((*me).save));
	ft_reset_save_board(&((*you).save));
	if (ft_find_nb_for_row(a, *me) == 5
			|| ft_find_nb_for_column(a, *me) == 5
			|| ft_find_nb_for_diag_up_left(a, *me) == 5
			|| ft_find_nb_for_diag_up_right(a, *me) == 5)
	{
		ft_putstr("\n***  I WON  ***\n\n\n");
		return (1);
	}
	if (ft_find_nb_for_row(a, *you) == 5
			|| ft_find_nb_for_column(a, *you) == 5
			|| ft_find_nb_for_diag_up_left(a, *me) == 5
			|| ft_find_nb_for_diag_up_right(a, *me) == 5)
	{
		ft_putstr("\n***  YOU WON  ***\n\n\n");
		return (1);
	}
	return (-1);
}

int			ft_won(t_all a, t_s *me, t_s *you)
{
	int		i;
	int		j;

	i = 0;
	while (a.grid[i])
	{
		j = 0;
		while (a.grid[i][j] && a.grid[i][j] == '.')
			++j;
		a.i = i;
		a.j = j;
		if (ft_won_2(a, me, you) == 1)
			return (1);
		++i;
	}
	return (-1);
}
