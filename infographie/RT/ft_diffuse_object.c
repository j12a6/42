/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diffuse_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:57:37 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/24 19:41:17 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>
static double	ft_max(double a, double b)
{
	if (b > a)
		return (b);
	return (a);
}

static t_c		ft_hit_a_sphere_light(t_obj obj, t_r *r, t_save *save, t_c *sf)
{
	double	facing;
	t_v		light_d;
	t_c		tmp1;
	t_c		tmp2;

	ft_init_color(&tmp2, 0, 0, 0);
	if (save->i == 1 && ((((t_sph ***)obj.type)[save->i][save->j])->em.r > 0
						 || (((t_sph ***)obj.type)[save->i][save->j])->em.g > 0
						 || (((t_sph ***)obj.type)[save->i][save->j])->em.b > 0))
	{
		ft_vect_difference(&light_d, (((t_sph ***)obj.type)[save->i][save->j])->c, r->p_hit);
		ft_normalize_vect(&light_d);
		facing = ft_dot_product(r->n_hit, light_d);
		facing = ft_max(0, facing);
		ft_mult_color_by_nb(&tmp1, *sf, facing);
		ft_mult_color_by_color(&tmp2, tmp1, (((t_sph ***)obj.type)[save->i][save->j])->em);
	}
	return (tmp2);
}

int		ft_diffuse_object(t_obj obj, t_r *r, t_c *color, t_c sf)
{
	int		i;
	int		j;
	t_r		new_r;
	t_save	save;

	new_r = *r;
	save.i = -1;
	save.j = -1;
	new_r.t0 = MAX;
	new_r.t1 = MAX;
	new_r.tnear = MAX;
	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj.nb[i])
		{
			if (obj.intersect[i](&new_r, (obj.type)[i][j]) == 0)
			{
				if (new_r.t0 < new_r.tnear)
				{
					new_r.tnear = new_r.t0;
					save.i = i;
					save.j = j;
				}
			}
		}
	}
	ft_color_sum(color, *color, ft_hit_a_sphere_light(obj, r, &save, &sf));
	return (0);
}
