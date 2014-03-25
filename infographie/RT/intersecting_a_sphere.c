/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:38:26 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/25 10:26:29 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"
//ATTENTION !!!!!!!!!!!!!!!! Dans le cas ou on est dans la sphere -> jeff veut faire chier le monde

#include <stdio.h>
#include "libft.h"
static int	ft_find_sphere_inter(t_r *r, t_sph *sph)
{
	t_v			o_to_c;
	double		a;
	double		b;
	double		c;

	ft_vect_difference(&o_to_c, r->o_w, sph->c);
	a = ft_dot_product(r->d_w, r->d_w);
	b = 2 * ft_dot_product(r->d_w, o_to_c);
	c = ft_dot_product(o_to_c, o_to_c) - sph->r * sph->r;
	if (ft_nearest_solution(a, b, c, r) == -1)
		return (-1);
	if (r->t1 < 0)
		return (-1);
	if (r->t0 < 0)
		r->t0 = r->t1;
	return (0);
}

int			ft_intersect_a_sphere(t_r *r, void *data)
{
	t_sph	*sph;

	sph = (t_sph *)data;
	if (ft_find_sphere_inter(r, sph) == -1)
		return (-1);
	return (0);
}

