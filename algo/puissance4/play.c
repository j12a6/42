/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:41:36 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:31:07 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "puissance4.h"
#include "libft.h"

static int		ft_init_turn(t_s *me, t_s *you)
{
	time_t	tloc;
	int		turn;

	if (!((*me).save = (int *)malloc(sizeof(int) * BUF_SIZE)))
		return (-1);
	if (!((*you).save = (int *)malloc(sizeof(int) * BUF_SIZE)))
		return (-1);
	(*me).symb1 = 'X';
	(*me).symb2 = 'O';
	(*you).symb1 = 'O';
	(*you).symb2 = 'X';
	srand(time(&tloc));
	turn = rand() % 2;
	return (turn);
}

static int		ft_choose_where_to_play(t_all a)
{
	char	*line;
	int		nb;

	line = NULL;
	nb = 0;
	ft_putstr("\n\nEnter a number between 1 and ");
	ft_putnbr(a.li);
	ft_putchar('\n');
	while (get_next_line(0, &line))
	{
		nb = ft_atoi(line);
		if (nb > 0 && nb <= a.li && a.grid[nb - 1][0] == '.')
			return (nb - 1);
		ft_putstr("\nEnter a number between 1 and ");
		ft_putnbr(a.li);
		ft_putendl("\n");
		free((void *)line);
	}
	return (-1);
}

static int		ft_play_a_piece(t_all *a, t_s s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s.keep)
		++i;
	j = 0;
	while ((*a).grid[i][j] && (*a).grid[i][j + 1] && (*a).grid[i][j + 1] == '.')
		++j;
	(*a).grid[i][j] = s.symb1;
	return (0);
}

static int		ft_grid_is_full(char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
				return (-1);
			++j;
		}
		++i;
	}
	ft_putendl("\n***  DRAW GAME  ***\n");
	return (0);
}

int				ft_play_the_game(t_all *a, t_s *me, t_s *you)
{
	int		turn;

	if ((turn = ft_init_turn(me, you)) == -1)
		return (-1);
	while (ft_won(*a, me, you) == -1 && ft_grid_is_full((*a).grid) == -1)
	{
		if (turn == 0)
		{
			if (((*you).keep = ft_choose_where_to_play(*a)) == -1)
				return (-1);
			ft_play_a_piece(a, *you);
		}
		else
		{
			ft_update_grid_of_choices(*a, me, you);
			ft_play_a_piece(a, *me);
		}
		ft_putendl("\n");
		ft_print_grid(*a);
		turn = (turn == 0 ? 1 : 0);
	}
	return (0);
}
