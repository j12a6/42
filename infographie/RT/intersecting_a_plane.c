/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_plane.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:17:42 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 10:24:24 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

int		ft_intersect_a_plane(t_r *r, void *data)
{
	t_v			o_to_c;
	double		denom;
	t_pla		*pla;

	pla = (t_pla *)data;
	denom = ft_dot_product(r->d_w, pla->n);
	if (fabs(denom) < E6)
		return (-1);
	ft_vect_difference(&o_to_c, pla->c, r->o_w);
	r->t0 = ft_dot_product(pla->n, o_to_c) / denom;
	r->t1 = MAX;
	if (r->t0 > 0)
		return (0);
	return (-1);
}
