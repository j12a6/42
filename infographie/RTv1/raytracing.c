/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:46:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/12 20:25:55 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>


#include <mlx.h>
#include <math.h>
#include "ft_rtv1.h"

t_v			ft_diff_vect(t_v vect1, t_v vect2)
{
	t_v		vect;

	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return (vect);
}

double		ft_discriminant(double a, double b, double c)
{
	return (pow(b, 2) - 4.0 * a * c);
}

double		ft_nearest_solution(double a, double b, double c)
{
	double		sol1;
	double		sol2;
	double		delta;

	delta = ft_discriminant(a, b, c);
	if (delta < 0.0)
		return (-1);
	else if (delta == 0.0)
		return (-b / (2.0 * a));
	else
	{
		sol1 = (-b + sqrt(delta)) / (2.0 * a);
		sol2 = (-b - sqrt(delta)) / (2.0 * a);
		if (sol1 < sol2)
			return (sol1);
		else
			return (sol2);
	}
}

double		ft_vect_norm(t_v vect)
{
	return (sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2)));
}

double		ft_dot_product(t_v vect1, t_v vect2)
{
	double		result;

	result = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (result);
}

double		ft_is_in_sphere(t_cam cam, t_sph sph)
{
	double		a;
	double		b;
	double		c;
	double		sol;

	a = ft_dot_product(cam.d, cam.d);
	b = 2 * ft_dot_product(cam.d, ft_diff_vect(cam.e, sph.c));
	c = ft_dot_product(ft_diff_vect(cam.e, sph.c), ft_diff_vect(cam.e, sph.c))
		- pow(sph.r, 2);
	sol = ft_nearest_solution(a, b, c);
	return (sol);
}

void		ft_initialise_vect(t_v *vect, double x, double y, double z)
{
	vect->x = x; 
	vect->y = y; 
	vect->z = z; 
}

int		ft_raytracing(t_mlx *mlx)
{
	int			i;
	int			j;
	t_cam		cam;
	t_sph		sph;

	ft_initialise_vect(&(sph.c), 0, 0, -30);
	sph.r = 2.0;
	ft_initialise_vect(&(cam.e), 0, 0, 0);
	j = -1;
	while (++j < W_H)
	{
		i = -1;
		while (++i < W_W)
		{
			ft_initialise_vect(&(cam.d), PRJ_X(i), PRJ_Y(j), -1);
			if ((cam.sol= ft_is_in_sphere(cam, sph)) >= 0)
				ft_put_pixel_in_image(&(mlx->i), i, j);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}
