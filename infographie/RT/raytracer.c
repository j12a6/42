/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:00:00 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 21:10:49 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_init_save_and_ray(t_r *r, t_save *save)
{
	r->t0 = MAX;
	r->t1 = MAX;
	r->tnear = MAX;
	save->i = -1;
	save->j = -1;
	return (0);
}

t_c		ft_trace(t_obj obj, t_r *r, t_save *save)
{
	int		i;
	int		j;
	t_c		color;

	ft_init_save_and_ray(r, save);
	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj.nb[i])
		{
			if (obj.intersect[i](r, (obj.type)[i][j]) == 0 && r->t0 < r->tnear)
			{
				r->tnear = r->t0;
				save->i = i;
				save->j = j;
			}
		}
	}
	if (save->i == -1)
		return (obj.bg_clr);
	r->hit_i = save->i;
	r->hit_j = save->j;
	obj.treatment[save->i]((obj.type)[save->i][save->j], &color, &obj, r);
	return (color);
}

void	ft_init_ray(t_r *r)
{
	ft_init_vect(&r->o_w, 0, 0, 0);
	ft_init_vect(&r->d_w, 0, 0, 0);
	ft_init_vect(&r->p_hit, 0, 0, 0);
	ft_init_vect(&r->n_hit, 0, 0, 0);
}

int		raytracer(t_obj *obj, t_cam cam)
{
	int			i;
	int			j;
	t_r			r;
	double		**c2w;
	t_save		save;

	if (!(c2w = ft_init_matrix(&cam.b.vx, &cam.b.vy, &cam.b.vz)))
		return (-1);
	ft_init_ray(&r);
	r.o_w = cam.ro;
	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			obj->depth = 0;
			ft_find_pixel_pos_on_screen(&cam.rp, i, j);
			ft_mult_vect_by_matrix(&r.d_w, c2w, cam.rp);
			ft_vect_difference(&r.d_w, r.d_w, r.o_w);
			ft_normalize_vect(&r.d_w);
			obj->pixel[j][i] = ft_trace(*obj, &r, &save);
		}
	}
	return (0);
}
