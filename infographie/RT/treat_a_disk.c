/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_disk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 17:40:53 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:40:48 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_treat_a_disk(void *data, t_c *color, t_obj *obj, t_r *r)
{
	t_dis	*dis;
	double	mult;
	t_v		tmp;

	dis = (t_dis *)data;
	ft_mult_vect_by_nb(&r->p_hit, r->d_w, r->tnear);
	ft_vect_sum(&r->p_hit, r->p_hit, r->o_w);
	r->n_hit = dis->n;
	ft_normalize_vect(&r->n_hit);
	ft_mult_vect_by_nb(&tmp, r->n_hit, E4);
	ft_vect_sum(&r->p_hit, tmp, r->p_hit);
	mult = ft_hit_light(r, obj);
	ft_init_color(color, dis->sf.b * mult, dis->sf.g * mult, dis->sf.r * mult);
	return (0);
}
