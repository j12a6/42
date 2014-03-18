/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_plane.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:17:42 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/18 21:32:34 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_intersect_a_plane(t_r *r, void *data)
{
	t_v			o_to_c;
	double		denom;
	double		t0;
	t_pla		*pla;

	pla = (t_pla *)data;
	denom = ft_dot_product(r->d_w, pla->n);
	if (denom > E6)
	{
		ft_vect_difference(&o_to_c, pla->c, r->o_w);
		r->t0 = ft_dot_product(r->d_w, o_to_c) / denom;
		r->t1 = -1;
		if (t0 > 0)
			return (0);
	}
	return (-1);
}
