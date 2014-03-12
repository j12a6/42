/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:57:11 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 18:15:02 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_rtv1.h"

t_v			ft_transform_in_new_basis(t_v old, double **mat)
{
	t_v		new;

	new.x = old.x * mat[0][0] + old.y * mat[1][0]
			+ old.z * mat[2][0];
	new.y = old.x * mat[0][1] + old.y * mat[1][1]
			+ old.z * mat[2][1];
	new.z = old.x * mat[0][2] + old.y * mat[1][2]
			+ old.z * mat[2][2];
	return (new);
}

double		ft_is_in_cylinder(t_cyl cyl, t_v d_in_b2, t_v new_e)
{
	double		a;
	double		b;
	double		c;
	double		sol;

	a = pow(ft_vect_norm(ft_cross_product(d_in_b2, cyl.b.v3)), 2);
	b = 4 * (ft_dot_product(ft_cross_product(new_e, cyl.b.v3),
							ft_cross_product(d_in_b2, cyl.b.v3)));
	c = 4 * pow(ft_vect_norm(ft_cross_product(new_e, cyl.b.v3)), 2)
		- pow(cyl.r, 2);
	sol = ft_nearest_solution(a, b, c);
	return (sol);
}

double		ft_find_nearest_cylinder(int *ind, t_cam cam, t_cyll *cyll)
{
	t_cyll		*move;
	int			i;
	double		dist;
	double		min;
	t_v			d_in_b2;

	i = 0;
	move = cyll;
	if (!move)
		return (-1);
	d_in_b2 = ft_transform_in_new_basis(cam.d, move->cyl.mat);
	min = ft_is_in_cylinder(move->cyl, d_in_b2, move->cyl.ce);
	*ind = i;
	++i;
	while ((move = move->next))
	{
		dist = ft_is_in_cylinder(move->cyl, d_in_b2, move->cyl.ce);
		if (dist != -1 && (min == -1 || min > dist))
		{
			min = dist;
			*ind = i;
		}
		++i;
	}
	return (min);
}
