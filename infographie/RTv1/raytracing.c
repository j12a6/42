/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:46:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/14 09:19:21 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "ft_rtv1.h"

double		ft_vect_norm(t_v vect)
{
	return (sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2)));
}

void		ft_init_vect(t_v *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

int			ft_raytracing(t_mlx *mlx)
{
	int			i;
	int			j;
	t_cam		cam;
	t_sol		sol;

	ft_init_vect(&(cam.e), 0, 5, 10);
	j = -1;
	while (++j < W_H)
	{
		i = -1;
		while (++i < W_W)
		{
			ft_init_vect(&(cam.d), PRJ_X(i), PRJ_Y(j), -1);
			ft_find_nearest_object(&sol, mlx, cam);
			if (sol.c != '-')
				ft_put_pixel_in_image(mlx, i, j, sol);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
