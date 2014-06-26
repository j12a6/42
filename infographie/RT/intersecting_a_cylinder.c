/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_cylinder.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:45:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 21:08:05 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_find_coeff(t_r *r, t_v *c, t_cyl *cyl)
{
	if (cyl->flag == 'x')
	{
		c->x = r->d_w.z * r->d_w.z + r->d_w.y * r->d_w.y;
		c->y = 2 * (r->o_w.z * r->d_w.z + r->o_w.y * r->d_w.y);
		c->z = r->o_w.z * r->o_w.z + r->o_w.y * r->o_w.y - cyl->r * cyl->r;
	}
	else if (cyl->flag == 'y')
	{
		c->x = r->d_w.x * r->d_w.x + r->d_w.z * r->d_w.z;
		c->y = 2 * (r->o_w.x * r->d_w.x + r->o_w.z * r->d_w.z);
		c->z = r->o_w.x * r->o_w.x + r->o_w.z * r->o_w.z - cyl->r * cyl->r;
	}
	else if (cyl->flag == 'z')
	{
		c->x = r->d_w.x * r->d_w.x + r->d_w.y * r->d_w.y;
		c->y = 2 * (r->o_w.x * r->d_w.x + r->o_w.y * r->d_w.y);
		c->z = r->o_w.x * r->o_w.x + r->o_w.y * r->o_w.y - cyl->r * cyl->r;
	}
}

int		ft_intersect_a_cylinder(t_r *r, void *data)
{
	t_cyl	*cyl;
	t_r		new_r;
	t_v		coeff;

	cyl = (t_cyl *)data;
	new_r = *r;
	ft_vect_difference(&new_r.o_w, r->o_w, cyl->c);
	ft_find_coeff(&new_r, &coeff, cyl);
	if (ft_nearest_solution(coeff.x, coeff.y, coeff.z, &new_r) == -1)
		return (-1);
	r->t0 = new_r.t0;
	r->t1 = new_r.t1;
	if (r->t1 < 0)
		return (-1);
	if (r->t0 < 0)
		r->t0 = r->t1;
	return (0);
}
