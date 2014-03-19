/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diffuse_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:57:37 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/19 19:25:25 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	ft_max(double a, double b)
{
	if (b > a)
		return (b);
	return (a);
}

static int		ft_hit_a_sphere_light(t_obj obj, t_r *r, t_save *save, t_c *sf)
{
	int		facing;
	t_v		light_d;
	t_c		tmp;

	if (save->i == 1 && (obj.type[save.i][save.j])->em != 0)
	{
		ft_vect_difference(&light_d, (obj.type[save.i][save.j])->c, r-p_hit);
		ft_normalize_vect(&light_d);
		facing = ft_dot_product(r->n_hit, light_d)
		facing = ft_max(0, facing);
		ft_mult_color_by_nb(&tmp, sf * facing * (obj.type[save.i][save.j])->em);
		ft_color_sum(color, tmp);
	}
	return (0);
}

int		ft_diffuse_object(t_obj obj, t_r *r, t_c *color, t_c sf)
{
	int		i;
	int		j;
	t_c		color;
	t_r		new_r;
	t_save	save;
	t_c		tmp;

	new_r = *r;
	save.i = -1;
	save.j = -1;
	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj->nb[i])
		{
			if (obj.intersect[i](&new_r, (obj->type)[i][j]) == 0)
			{
				if (new_r->t0 < 0)
					new_r->t0 = new_r->t1;
				if (new_r->t0 > 0 && new_r->t0 < new_r->tnear)
				{
					new_r->tnear = new_r->t0;
					save->i = i;
					save->j = j;
				}
			}
		}
	}
	return (0);
}
