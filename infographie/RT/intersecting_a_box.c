/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_box.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 17:53:33 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/17 20:22:56 by jaubert          ###   ########.fr       */
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

void		ft_find_x_box(t_r *r, t_box box, double *tmin_x, double *tmax_x)
{
	if (r->d.x == 0)
	{
		*tmin_x = INT_MIN;
		*tmax_x = INT_MAX;
	}
	else
	{
		*tmin_x = (box.xmin - r->o.x) / r->d.x;
		*tmax_x = (box.xmax - r->o.x) / r->d.x;
	}
	if (*tmin_x > *tmax_x)
		ft_swap(tmin_x, tmax_x);
}

void		ft_find_y_box(t_r *r, t_box box, double *tmin_y, double *tmax_y)
{
	if (r->d.y == 0)
	{
		*tmin_y = INT_MIN;
		*tmax_y = INT_MAX;
	}
	else
	{
		*tmin_y = (box.ymin - r->o.y) / r->d.y;
		*tmax_y = (box.ymax - r->o.y) / r->d.y;
	}
	if (*tmin_y > *tmax_y)
		ft_swap(tmin_y, tmax_y);
}

void		ft_find_z_box(t_r *r, t_box box, double *tmin_z, double *tmax_z)
{
	if (r->d.z == 0)
	{
		*tmin_z = INT_MIN;
		*tmax_z = INT_MAX;
	}
	else
	{
		*tmin_z = (box.ymin - r->o.z) / r->d.z;
		*tmax_z = (box.ymax - r->o.z) / r->d.z;
	}
	if (*tmin_z > *tmax_z)
		ft_swap(tmin_z, tmax_z);
}

int			ft_intersect_a_box(t_r *r, t_box box)
{
	double		tmin;
	double		tmax;
	double		tmp1;
	double		tmp2;

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
	if (tmin > r->tmax || tmax < r->tmin) // ATTENTION INDECIS SUR LA DERNIERE CDT
		return (-1);
	r->tmin = (r->tmin < tmin) ? tmin : r->tmin; // A quoi sert vraiment tmin & tmax
	r->tmax = (r->tmax > tmax) ? tmax : r->tmax; //idem
	return (0);
}
