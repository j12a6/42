/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:12:05 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 21:12:56 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	ft_find_sph_normal(t_r *r, t_v c)
{
	t_v		tmp;

	ft_mult_vect_by_nb(&tmp, r->d_w, r->tnear);
	ft_vect_sum(&r->p_hit, r->o_w, tmp);
	ft_vect_difference(&r->n_hit, r->p_hit, c);
	ft_normalize_vect(&r->n_hit);
	if (ft_dot_product(r->d_w, r->n_hit) > 0)
		return (-1);
	ft_mult_vect_by_nb(&tmp, r->n_hit, E4);
	ft_vect_sum(&r->p_hit, tmp, r->p_hit);
	return (0);
}

int			ft_treat_a_sphere(void *data, t_c *color, t_obj *obj, t_r *r)
{
	t_sph		*sph;
	double		mult;

	sph = (t_sph *)data;
	if (ft_find_sph_normal(r, sph->c) == -1)
		ft_init_color(color, sph->sf.b / 2, sph->sf.g / 2, sph->sf.r / 2);
	else
	{
		if ((((t_sph ***)obj->type)[SPH][r->hit_j])->em.r > 0)
			*color = sph->sf;
		else
		{
			mult = ft_hit_light(r, obj);
			ft_init_color(color, sph->sf.b * mult,
							sph->sf.g * mult, sph->sf.r * mult);
		}
	}
	return (0);
}
