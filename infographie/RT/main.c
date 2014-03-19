/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:02:27 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/19 19:25:23 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

double	ft_mix(double a, double b, double mix)
{
	return (b * mix + a * (1 - mix));
}

int		ft_init_changer_nom(t_r *r, t_save *save)
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
	int			i;
	int			j;
	t_c			color;

	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj->nb[i])
		{
			if (obj.intersect[i](&r, (obj->type)[i][j]) == 0)
			{
				if (r->t0 < 0)
					r->t0 = r->t1;
				if (r->t0 > 0 && r->t0 < r->tnear)
				{
					r->tnear = r->t0;
					save->i = i;
					save->j = j;
				}
			}
		}
	}
	if (save->i == -1)
		return (obj->bg_clr);
	obj->treatment[save->i](r, (obj->type)[save->i][save->j], &color, obj);
	return (color);
}


int			raytracer(t_obj obj, t_cam cam)
{
	double		i;
	double		j;
	t_r			r;
	t_v			rp_w;
	double		**c2w;
	t_v			pixel[HEIGHT * WIDTH];
	t_save		save;

	ft_init_vect(&cam.ro, 0.0, 0.0, 0.0);
	if (!(c2w = ft_init_matrix(cam.b.vx, cam.b.vy, cam.b.vz, cam.trans)))
		return (-1);
//			ft_mult_vect_by_matrix(&r.o, c2w, ro_c);
	r.o_w = cam.ro;//delete ligne au dessus
	j = -1;
	while  (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			save.i = -1;
			save.j = -1;
			obj.depth = 0;
			ft_find_pixel_pos_on_screen(&cam.rp, i, j);
			ft_mult_vect_by_matrix(&rp_w, c2w, cam.rp);
			ft_vect_difference(&r.d_w, rp_w, r.o_w);
			ft_normalize_vect(&r.d_w);
			pixel = ft_trace(obj, r, &save);
			++pixel;
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_obj		obj;
	t_cam		cam;

	if (ac != 2 || !av[2])
		return (ft_error("Please choose one scene", "", -1));
/*	if (ft_parser(av[2], &obj) == -1)
		return (-1);*/
	ft_init_vect(&(cam.b.vx), 1.0, 0.0, 0.0);
	ft_init_vect(&(cam.b.vy), 0.0, 1.0, 0.0);
	ft_init_vect(&(cam.b.vz), 0.0, 0.0, 1.0);
	ft_init_vect(&cam.trans, 0.0, 0.0, 0.0);
	raytracer(obj, cam);
	return (0);
}
