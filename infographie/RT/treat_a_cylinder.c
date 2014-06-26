/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:53:56 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:40:41 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_init_normal(t_v *n_hit, t_v p_hit, t_cyl *cyl)
{
	if (cyl->flag == 'x')
	{
		n_hit->x = 0;
		n_hit->y = p_hit.y - cyl->c.y;
		n_hit->z = p_hit.z - cyl->c.z;
	}
	else if (cyl->flag == 'y')
	{
		n_hit->y = 0;
		n_hit->x = p_hit.x - cyl->c.x;
		n_hit->z = p_hit.z - cyl->c.z;
	}
	else if (cyl->flag == 'z')
	{
		n_hit->z = 0;
		n_hit->y = p_hit.y - cyl->c.y;
		n_hit->x = p_hit.x - cyl->c.x;
	}
}

int				ft_treat_a_cylinder(void *data, t_c *color, t_obj *obj, t_r *r)
{
	t_cyl		*cyl;
	double		mult;

	cyl = (t_cyl *)data;
	ft_mult_vect_by_nb(&r->p_hit, r->d_w, r->tnear);
	ft_vect_sum(&r->p_hit, r->p_hit, r->o_w);
	ft_init_normal(&r->n_hit, r->p_hit, cyl);
	ft_normalize_vect(&r->n_hit);
	mult = ft_hit_light(r, obj);
	ft_init_color(color, cyl->sf.b * mult, cyl->sf.g * mult, cyl->sf.r * mult);
	return (0);
}
