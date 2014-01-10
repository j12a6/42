/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:47:40 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 18:56:02 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "ft_fdf.h"

static void		ft_line_same_z(t_coord c, t_fdf *e)
{
	double		x;

	x = c.x1;
	while (x <= c.x2)
	{
		mlx_pixel_put(e->mlx_ptr, e->win, x,
		c.y1 + ((c.y2 - c.y1) * (x - c.x1)) / (c.x2 - c.x1), COLOR_UP);
		x = x + 0.05;
	}
}

static void		ft_line_diff_z(t_coord c, t_fdf *e)
{
	double		x;

	x = c.x1;
	while (x <= c.x2)
	{
		mlx_pixel_put(e->mlx_ptr, e->win, x,
		c.y1 + ((c.y2 - c.y1) * (x - c.x1)) / (c.x2 - c.x1), COLOR_DOWN);
		x = x + 0.05;
	}
}

static void		ft_line_hor(t_fdf e, int **tab, int nb_line, int nb_col)
{
	int			i;
	int			j;
	t_coord		c;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_col - 1)
		{
			c.x1 = OGN + (C1 * j - C2 * i) * A;
			c.x2 = OGN + (C1 * (j + 1) - C2 * i) * A;
			c.y1 = OGN + (-1 * tab[i][j] + C1 / 2 * j + C2 / 2 * i) * A;
			c.y2 = OGN + (-1 * tab[i][j + 1] + C1 / 2 * (j + 1)
					+ C2 / 2 * i) * A;
			if (tab[i][j] == 0 && tab[i][j + 1] == 0)
				ft_line_same_z(c, &e);
			else
				ft_line_diff_z(c, &e);
			j++;
		}
		i++;
	}
}

static void		ft_line_ver(t_fdf e, int **tab, int nb_line, int nb_col)
{
	int			i;
	int			j;
	t_coord		c;

	j = 0;
	while (j < nb_col)
	{
		i = 0;
		while (i < nb_line - 1)
		{
			c.x1 = OGN + (C1 * j - C2 * (i + 1)) * A;
			c.x2 = OGN + (C1 * j - C2 * i) * A;
			c.y1 = OGN + (-1 * tab[i + 1][j] + C1 / 2 * j
					+ C2 / 2 * (i + 1)) * A;
			c.y2 = OGN + (-1 * tab[i][j] + C1 / 2 * j + C2 / 2 * i) * A;
			if (tab[i][j] == 0 && tab[i + 1][j] == 0)
				ft_line_same_z(c, &e);
			else
				ft_line_diff_z(c, &e);
			i++;
		}
		j++;
	}
}

int				expose_hook(t_fdf *e)
{
	ft_line_hor(*e, e->tab, e->nb_line, e->nb_col);
	ft_line_ver(*e, e->tab, e->nb_line, e->nb_col);
	return (0);
}
