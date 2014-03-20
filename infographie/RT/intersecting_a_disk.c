/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_disk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:47:21 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/20 16:09:06 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

int		ft_intersect_a_disk(t_r *r, void *data)
{
	t_v			o_to_c;
	t_v			o_to_p;
	t_v			c_to_p;
	double		denom;
	t_dis		*dis;

	dis = (t_dis *)data;
	denom = ft_dot_product(r->d_w, dis->n);
	if (denom > E6)
	{
		ft_vect_difference(&o_to_c, dis->c, r->o_w);
		r->t0 = ft_dot_product(r->d_w, o_to_c) / denom;
		r->t1 = -1;
		if (r->t0 > 0)
		{
			ft_mult_vect_by_nb(&o_to_p, r->d_w, r->t0);
			if (ft_dot_product(c_to_p, c_to_p) <= pow(dis->r, 2))
				return (0);
		}
	}
	return (-1);
}
