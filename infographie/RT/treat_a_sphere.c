/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:12:05 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 15:03:59 by makoudad         ###   ########.fr       */
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
/*
static int	ft_find_sph_refl_clr(t_r *r, t_c *refl_clr, t_obj obj, double *fresnel)
{
	t_v		tmp;
	double	facing_ratio;
	t_r		new_r;
	t_save	save;

	new_r = *r;
	facing_ratio = -ft_dot_product(r->d_w, r->n_hit);
	*fresnel = ft_mix(pow(1 - facing_ratio, 3), 1, 0.1);
	ft_mult_vect_by_nb(&tmp, r->n_hit, 2 * ft_dot_product(r->d_w, r->n_hit));
	ft_vect_difference(&new_r.d_w, r->d_w, tmp);
	ft_normalize_vect(&new_r.d_w);
	ft_mult_vect_by_nb(&tmp, r->n_hit, E4);
	ft_vect_sum(&new_r.o_w, r->p_hit, tmp);
	*refl_clr = ft_trace(obj, &new_r, &save);
	return (0);
}

static int	ft_find_sph_refr_clr(t_r *r, t_c *refr_clr, t_obj obj, double eta)
{
	double		cosi;
	t_r			new_r;
	t_save		save;
	double		k;
	t_v			tmp;
	t_v			tmp2;

	new_r = *r;
	cosi = -ft_dot_product(r->d_w, r->n_hit);
	k = 1 - eta * eta * (1 - cosi * cosi);
	ft_mult_vect_by_nb(&tmp, r->d_w, eta);
	ft_mult_vect_by_nb(&tmp2, r->n_hit, eta * cosi - sqrt(k));
	ft_vect_sum(&new_r.d_w, tmp, tmp2);
	ft_normalize_vect(&new_r.d_w);
	ft_mult_vect_by_nb(&tmp, r->n_hit, E4);
	ft_vect_difference(&new_r.o_w, r->p_hit, tmp);
	*refr_clr = ft_trace(obj, &new_r, &save);
	return (0);
}
*/

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
			ft_init_color(color, sph->sf.b * mult, sph->sf.g * mult, sph->sf.r * mult);
		}
	}
	return (0);
}
