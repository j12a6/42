/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_box.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:53:33 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 09:41:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_swap(double *tmin, double *tmax)
{
	double		tmp;

	tmp = *tmin;
	*tmin = *tmax;
	*tmax = tmp;
}

void		ft_find_x_box(t_r *r, t_box *box, double *tmin_x, double *tmax_x)
{
	if (r->d_w.x == 0)
	{
		*tmin_x = MIN;
		*tmax_x = MAX;
	}
	else
	{
		*tmin_x = (box->xmin - r->o_w.x) / r->d_w.x;
		*tmax_x = (box->xmax - r->o_w.x) / r->d_w.x;
	}
	if (*tmin_x > *tmax_x)
		ft_swap(tmin_x, tmax_x);
}

void		ft_find_y_box(t_r *r, t_box *box, double *tmin_y, double *tmax_y)
{
	if (r->d_w.y == 0)
	{
		*tmin_y = MIN;
		*tmax_y = MAX;
	}
	else
	{
		*tmin_y = (box->ymin - r->o_w.y) / r->d_w.y;
		*tmax_y = (box->ymax - r->o_w.y) / r->d_w.y;
	}
	if (*tmin_y > *tmax_y)
		ft_swap(tmin_y, tmax_y);
}

void		ft_find_z_box(t_r *r, t_box *box, double *tmin_z, double *tmax_z)
{
	if (r->d_w.z == 0)
	{
		*tmin_z = MIN;
		*tmax_z = MAX;
	}
	else
	{
		*tmin_z = (box->ymin - r->o_w.z) / r->d_w.z;
		*tmax_z = (box->ymax - r->o_w.z) / r->d_w.z;
	}
	if (*tmin_z > *tmax_z)
		ft_swap(tmin_z, tmax_z);
}

int			ft_intersect_a_box(t_r *r, void *data)
{
	double		tmin;
	double		tmax;
	double		tmp1;
	double		tmp2;
	t_box		*box;

	box = (t_box *)data;
	ft_find_x_box(r, box, &tmin, &tmax);
	ft_find_y_box(r, box, &tmp1, &tmp2);
	if (tmp1 > tmax || tmin > tmp2)
		return (-1);
	tmin = (tmp1 > tmin) ? tmp1 : tmin;
	tmax = (tmp2 < tmax) ? tmp2 : tmax;
	ft_find_z_box(r, box, &tmp1, &tmp2);
	if (tmp1 > tmax || tmin > tmp2)
		return (-1);
	tmin = (tmp1 > tmin) ? tmp1 : tmin;
	tmax = (tmp2 < tmax) ? tmp2 : tmax;
	r->t0 = tmin;
	r->t1 = tmax;
	return (0);
}
