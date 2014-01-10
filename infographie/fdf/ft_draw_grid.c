/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:12:02 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 19:06:11 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "ft_fdf.h"

int				**ft_create_tab(t_lst *list, int nb_line, int nb_col)
{
	int			i;
	int			j;
	int			**tab;
	char		**tmp;

	tab = (int **)malloc(sizeof(**tab) * nb_line * nb_line);
	i = 0;
	while (i < nb_line)
	{
		j = 0;
		tab[i] = (int *)malloc(sizeof(**tab) * nb_col);
		tmp = ft_strsplit(list->line, ' ');
		while (j < nb_col)
		{
			tab[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		list = list->next;
		i++;
	}
	return (tab);
}

int		key_hook(int keycode, t_fdf *e)
{
	e->win = NULL;
	if (keycode == 65307)
		exit(0);
	return (0);
}

void			ft_draw_grid(int **tab, int nb_line, int nb_col)
{
	t_fdf	e;

	e.mlx_ptr = mlx_init();
	e.win = mlx_new_window(e.mlx_ptr, 1500, 1500, "image_42");
	e.tab = tab;
	e.nb_line = nb_line;
	e.nb_col = nb_col;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx_ptr);
}
