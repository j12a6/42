/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:53:56 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:41:00 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_init_normal(t_v *n_hit, t_v p_hit, t_con *con)
{
	if (con->flag == 'x')
	{
		n_hit->x = 0;
		n_hit->y = p_hit.y - con->c.y;
		n_hit->z = p_hit.z - con->c.z;
	}
	else if (con->flag == 'y')
	{
		n_hit->y = 0;
		n_hit->x = p_hit.x - con->c.x;
		n_hit->z = p_hit.z - con->c.z;
	}
	else if (con->flag == 'z')
	{
		n_hit->z = 0;
		n_hit->y = p_hit.y - con->c.y;
		n_hit->x = p_hit.x - con->c.x;
	}
}

int			ft_treat_a_cone(void *data, t_c *color, t_obj *obj, t_r *r)
{
	t_con		*con;
	double		mult;

	con = (t_con *)data;
	ft_mult_vect_by_nb(&r->p_hit, r->d_w, r->tnear);
	ft_vect_sum(&r->p_hit, r->p_hit, r->o_w);
	ft_init_normal(&r->n_hit, r->p_hit, con);
	ft_normalize_vect(&r->n_hit);
	mult = ft_hit_light(r, obj);
	ft_init_color(color, con->sf.b * mult, con->sf.g * mult, con->sf.r * mult);
	return (0);
}
