/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_on_vectors_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 10:24:09 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/19 11:13:51 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_vect(t_v *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

void	ft_vect_opposite(t_v *vect, t_v v1)
{
	vect->x = -v1.x;
	vect->y = -v1.y;
	vect->z = -v1.z;

}

void	ft_vect_sum(t_v *vect, t_v v1, t_v v2)
{
	vect->x = v1.x + v2.x;
	vect->y = v1.y + v2.y;
	vect->z = v1.z + v2.z;
}

void	ft_mult_vect_by_scalar(t_v *vect, t_v v1, double scalar)
{
	vect->x = v1.x * scalar;
	vect->y = v1.y * scalar;
	vect->z = v1.z * scalar;
}
