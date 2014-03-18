/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:38:26 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/18 21:31:22 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static int	ft_find_sphere_inter(t_r *r, t_sph *sph)
{
	t_v			o_to_c;
	double		t_oc;
	double		t_pc;
	double		d2;
	double		r2;

	ft_vect_difference(&o_to_c, sph->c, r->o_w);
	t_oc = ft_dot_product(r->d_w, o_to_c);
	if (t_oc < 0)
		return (-1);
	d2 = ft_dot_product(o_to_c, o_to_c) - t_oc;
	r2 = pow(sph->r, 2);
	if (d2 > r2)
		return (1);
	t_pc = sqrt(r2 - d2);
	r->t0 = t_oc - t_pc;
	r->t1 = t_oc + t_pc;
	return (0);
}

int			ft_intersect_a_sphere(t_r *r, void *data)
{
	t_sph		*sph;

	sph = (t_sph *)data;
	if (ft_find_sphere_inter(r, sph) == -1)
		return (-1);
	return (0);
}

