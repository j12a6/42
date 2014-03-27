/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_cylinder.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:45:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 11:39:01 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_compute_ray_in_new_system(t_r *r, t_cy *cyl)
{
	return (0);
}

int		ft_intersect_a_cylinder(t_r *r, void *data)
{
	t_cyl	*cyl;
	t_r		new_r;

	cyl = (t_cyl *)data;
	new_r = *r;
	ft_compute_ray_in_new_system(r, cyl);
	ft_
	return (0);
}
