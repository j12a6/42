/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:23:46 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/27 22:51:00 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double		ft_hit_or_not(t_r *r, t_obj *obj, int light, t_v *n)
{
	int		i;
	int		j;
	t_save	save;

	ft_init_save_and_ray(r, &save);
	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj->nb[i])
		{
			if ((i != SPH || (i == SPH && j != light))
				&& obj->intersect[i](r, (obj->type)[i][j]) == 0
				&& r->t0 < r->tnear)
			{
				r->tnear = r->t0;
				save.i = i;
				save.j = j;
			}
		}
	}
	if (save.i != r->hit_i || save.j != r->hit_j)
		return (1);
	return (1 - ft_dot_product(*n, r->d_w));
}

double				ft_hit_light(t_r *r, t_obj *obj)
{
	int		i;
	t_r		r_l;
	t_sph	*light;

	i = 0;
	while (i < obj->nb[SPH] && (((t_sph ***)obj->type)[SPH][i])->em.b == 0)
		++i;
	if (i == obj->nb[SPH])
		return (1);
	light = ((t_sph ***)obj->type)[SPH][i];
	ft_init_vect(&r_l.o_w, light->c.x, light->c.y, light->c.z);
	ft_vect_difference(&r_l.d_w, r->p_hit, r_l.o_w);
	ft_normalize_vect(&r_l.d_w);
	r_l.hit_i = r->hit_i;
	r_l.hit_j = r->hit_j;
	return (ft_hit_or_not(&r_l, obj, i, &r->n_hit));
}
