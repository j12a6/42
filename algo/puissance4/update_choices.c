/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_choices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:47:42 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:30:36 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int		ft_win_now(t_s *s)
{
	int		k;

	k = 0;
	while (k < BUF_SIZE)
	{
		if ((*s).save[k] == 4)
			return (1);
		++k;
	}
	return (0);
}

static int		ft_compute_mixed_value(int *save)
{
	return (26 * save[0] + 15 * save[1] + 10 * (save[2] + save[3]));
}

static void		ft_fill_save_board(t_all a, t_s *s)
{
	(*s).choices[a.i] = 0;
	ft_reset_save_board(&((*s).save));
	(*s).save[0] = ft_find_nb_for_row(a, *s);
	(*s).save[1] = ft_find_nb_for_column(a, *s);
	(*s).save[2] = ft_find_nb_for_diag_up_left(a, *s);
	(*s).save[3] = ft_find_nb_for_diag_up_right(a, *s);
}

static int		ft_number_of_awesomeness(t_all a, t_s *me, t_s *you)
{
	ft_fill_save_board(a, me);
	ft_fill_save_board(a, you);
	if (ft_win_now(me) == 1)
		(*me).choices[a.i] += ME_4_1;
	else if (ft_win_now(you) == 1)
		(*me).choices[a.i] += YOU_4_1;
	else
		(*me).choices[a.i] = ft_compute_mixed_value((*me).save)
			+ ft_compute_mixed_value((*you).save) / 2;
	return (0);
}

int				ft_update_grid_of_choices(t_all a, t_s *me, t_s *you)
{
	int		i;
	int		j;
	int		max;

	max = 0;
	i = 0;
	while (a.grid[i])
	{
		j = 0;
		while (a.grid[i][j] && a.grid[i][j + 1] && a.grid[i][j + 1] == '.')
			++j;
		a.i = i;
		a.j = j;
		ft_number_of_awesomeness(a, me, you);
		if ((*me).choices[i] > max)
		{
			max = (*me).choices[i];
			(*me).keep = i;
		}
		++i;
	}
	return (0);
}
