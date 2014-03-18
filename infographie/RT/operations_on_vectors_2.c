/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_on_vectors_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 10:24:09 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/18 15:03:32 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_vect(t_v *vect, double x, double y, double z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

void	ft_multiply_vect_by_scalar(t_v *vect, double scalar, t_v v1)
{
	vect->x = scalar * v1.x;
	vect->y = scalar * v1.y;
	vect->z = scalar * v1.z;
}
