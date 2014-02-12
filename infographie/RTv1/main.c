/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:06:32 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/12 20:25:52 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "ft_rtv1.h"
#include "libft.h"

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 65307)
	{
		goclean();
		exit(0);
		mlx = NULL;
	}
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	ft_raytracing(mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 1 || !av[0])
		return (-1);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, W_W, W_H, "RTv1");
	mlx.img = mlx_new_image(mlx.mlx, W_W, W_H);
	mlx.i.data = mlx_get_data_addr(mlx.img, &(mlx.i.bpp), &(mlx.i.sl),
									&(mlx.i.endian));
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
