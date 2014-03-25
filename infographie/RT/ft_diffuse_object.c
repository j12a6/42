/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diffuse_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:57:37 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/25 18:14:36 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>
#include "libft.h"
static t_c		ft_hit_a_sphere_light(t_obj obj, t_r *r, t_save *save, t_c *sf)
{
	double	facing;
	t_v		light_d;
	t_c		tmp1;
	t_c		tmp2;

	ft_init_color(&tmp2, 0, 0, 0);
	facing = ft_dot_product(r->n_hit, light_d);
	facing = facing > 0 ? facing : 0;
	ft_mult_color_by_nb(&tmp1, *sf, facing);
	ft_mult_color_by_color(&tmp2, tmp1, (((t_sph ***)obj.type)[SPH][save->i])->em);
	return (tmp2);
}

int		ft_diffuse_object(t_obj obj, t_r *r, t_c *color, t_c sf)
{
	int		i;
	int		j;
	t_r		new_r;
	t_save	save;
	int		trans;
	t_v		light_d;

	new_r = *r;
	save.i = -1;
	save.j = -1;
	new_r.t0 = MAX;
	new_r.t1 = MAX;
	new_r.tnear = MAX;
	i = -1;
	while (++i < obj.nb[SPH])
	{
		if (((((t_sph ***)obj.type)[SPH][i])->em.r > 0
			 || (((t_sph ***)obj.type)[SPH][i])->em.g > 0
			 || (((t_sph ***)obj.type)[SPH][i])->em.b > 0))
		{
			trans = 1;
			ft_vect_difference(&light_d, (((t_sph ***)obj.type)[SPH][i])->c, new_r.p_hit);
			ft_normalize_vect(&light_d);
			new_r.d_w = light_d;
			j = -1;
			while (++j < obj.nb[SPH])
			{
				if (i != j)
				{
					if (obj.intersect[SPH](&new_r, (obj.type)[SPH][j]) == 0)
					{
						trans = 0;
						break ;
					}
				}
			}
			save.i = i;
			if (trans == 1)
				ft_color_sum(color, *color, ft_hit_a_sphere_light(obj, &new_r, &save, &sf));
		}
	}
	printf("%d, %d, %d\n", color->b, color->g, color->r);
	return (0);
}
