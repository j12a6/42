/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:57:11 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 18:15:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rtv1.h"

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

double		ft_find_nearest_sphere(int *ind, t_cam cam, t_sl *sl)
{
	t_sl		*move;
	int			i;
	double		dist;
	double		min;

	i = 0;
	move = sl;
	if (!move)
		return (-1);
	min = ft_is_in_sphere(cam, move->sph);
	*ind = i;
	++i;
	while ((move = move->next))
	{
		dist = ft_is_in_sphere(cam, move->sph);
		if (dist != -1 && (min == -1 || min > dist))
		{
			min = dist;
			*ind = i;
		}
		++i;
	}
	return (min);
}
