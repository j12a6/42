/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:19:36 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:22:55 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "puissance4.h"
#include "libft.h"

static int	ft_save_grid_size(char *s1, char *s2, int *li, int *co)
{
	*li = ft_atoi(s2);
	*co = ft_atoi(s1);
	if (*li < 7)
	{
		ft_putstr(s1);
		ft_putendl("\033[33m: is not a valable argument\033[0m");
		ft_putendl("\033[33mAt least 7 columns are needed\033[0m");
		return (-1);
	}
	if (*co < 6)
	{
		ft_putstr(s2);
		ft_putendl("\033[33m: is not a valable argument\033[0m");
		ft_putendl("\033[33mAt least 6 lines are needed\033[0m");
		return (-1);
	}
	return (0);
}

static int	ft_init_grid(char ***grid, int li, int co)
{
	int		i;
	int		j;

	if (!(*grid = (char **)malloc(sizeof(char *) * (li + 1))))
		return (-1);
	i = 0;
	while (i < li)
	{
		if (!((*grid)[i] = (char *)malloc(sizeof(char) * (co + 1))))
			return (-1);
		j = 0;
		while (j < co)
		{
			(*grid)[i][j] = '.';
			++j;
		}
		(*grid)[i][co] = '\0';
		++i;
	}
	(*grid)[li] = NULL;
	return (0);
}

static int	ft_init_grid_of_choices(int **choices, int li)
{
	int		i;

	if (!((*choices) = (int *)malloc(sizeof(int) * li)))
		return (-1);
	i = 0;
	while (i < li)
	{
		(*choices)[i] = 0;
		++i;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_all	a;
	t_s		me;
	t_s		you;

	if (ac != 3 && ac != 1)
	{
		ft_putendl("\033[33m0 or 2 arguments needed to play\033[0m");
		return (-1);
	}
	if (ac == 1)
	{
		a.co = 6;
		a.li = 7;
	}
	if (ac == 3 && ft_save_grid_size(av[1], av[2], &(a.li), &(a.co)) == -1)
		return (-1);
	if (ft_init_grid(&(a.grid), a.li, a.co) == -1)
		return (-1);
	if ((ft_init_grid_of_choices(&(me.choices), a.li) == -1)
		|| (ft_init_grid_of_choices(&(you.choices), a.li) == -1))
		return (-1);
	if (ft_play_the_game(&a, &me, &you) == -1)
		return (-1);
	return (0);
}
