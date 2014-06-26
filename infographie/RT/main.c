/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:02:27 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:56:27 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "rt.h"

int		key_hook(int key, t_mlx *mlx)
{
	t_mlx	*tmp;

	tmp = mlx;
	mlx = tmp;
	if (key == 65307)
	{
		mlx = NULL;
		exit(0);
	}
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_cam		cam;
	t_mlx		mlx;

	if (ac != 2 || !av[1])
		return (ft_error("Please choice next scene: [1 - 2]", "", -1));
	ft_init_camera(&cam);
	ft_init_object_structure(&mlx.obj);
	if (ft_do_scene(&mlx.obj, av[1]) == -1)
		return (ft_error("Please choice next scene: [1 - 2]", "", -1));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "RT");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.i.data = mlx_get_data_addr(mlx.img, &(mlx.i.bpp), &(mlx.i.sl),
									&(mlx.i.endian));
	mlx_key_hook(mlx.win, key_hook, &mlx);
	raytracer(&mlx.obj, cam);
	ft_draw(&mlx);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
