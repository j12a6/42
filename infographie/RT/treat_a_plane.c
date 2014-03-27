/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 17:41:40 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 15:04:53 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_treat_a_plane(void *data, t_c *color, t_obj *obj, t_r *r)
{
	t_pla	*pla;
	double	mult;
	t_v		tmp;

	pla = (t_pla *)data;
	ft_mult_vect_by_nb(&r->p_hit, r->d_w, r->tnear);
	ft_vect_sum(&r->p_hit, r->p_hit, r->o_w);
	r->n_hit = pla->n;
	ft_mult_vect_by_nb(&tmp, r->n_hit, E4);
	ft_vect_sum(&r->p_hit, tmp, r->p_hit);
	mult = ft_hit_light(r, obj);
	ft_init_color(color, pla->sf.b * mult, pla->sf.g * mult, pla->sf.r * mult);
	return (0);
}
