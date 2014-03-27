/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_on_vectors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 16:38:28 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/26 10:21:59 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

double	ft_vect_norm(t_v *vect)
{
	return (sqrt(vect->x * vect->x + vect->y * vect->y + vect->z * vect->z));
}

void	ft_normalize_vect(t_v *vect)
{
	double	norm;

	norm = ft_vect_norm(vect);
	vect->x *= 1 / norm;
	vect->y *= 1 / norm;
	vect->z *= 1 / norm;
}

void	ft_vect_difference(t_v *vect, t_v vect1, t_v vect2)
{
	vect->x = vect1.x - vect2.x;
	vect->y = vect1.y - vect2.y;
	vect->z = vect1.z - vect2.z;
}

double	ft_dot_product(t_v vect1, t_v vect2)
{
	return (vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z);
}

void	ft_cross_product(t_v *vect, t_v *vect1, t_v *vect2)
{
	vect->x = vect1->y * vect2->z - vect1->z * vect2->y;
	vect->y = -(vect1->x * vect2->z - vect1->z * vect2->x);
	vect->z = vect1->x * vect2->y - vect1->y * vect2->x;
}
