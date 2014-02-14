/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 09:45:39 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/13 17:15:45 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_v			ft_diff_vect(t_v vect1, t_v vect2)
{
	t_v		vect;

	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return (vect);
}

double		ft_dot_product(t_v vect1, t_v vect2)
{
	double	result;

	result = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (result);
}
