/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:02:27 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/18 21:29:55 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_trace(t_obj obj, t_r r, t_save *save)
{
	double		t0;
	double		t1;
	double		tnear;
	int			i;
	int			j;

	t0 = MAX;
	t1 = MAX;
	tnear = MAX;
	save = NULL;
	i = -1;
	while (++i < NB_TYPE)
	{
		j = -1;
		while (++j < obj.nb[i])
		{
			if (obj.fct[i](&r, obj.type[i][j]) == 0)
			{
				if (r.t0 < 0)
					r.t0 = r.t1;
				if (r.t0 > 0 && r.t0 < tnear)
				{
					tnear = r.t0;
					save->i = i;
					save->j = j;
				}
			}
		}
	}
}


int			raytracer(t_obj obj, t_cam cam)
{
	double		i;
	double		j;
	t_r			r;
	t_v			rp_w;
	double		**c2w;
	/*t_v			pixel;*/
	t_save		save;

	ft_init_vect(&cam.ro, 0.0, 0.0, 0.0);
	if (!(c2w = ft_init_matrix(cam.b.vx, cam.b.vy, cam.b.vz, cam.trans)))
		return (-1);
//			ft_multiply_vect_and_matrix(&r.o, c2w, ro_c);
	r.o_w = cam.ro;//delete ligne au dessus
	j = -1;
	while  (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ft_find_pixel_pos_on_screen(&cam.rp, i, j);
			ft_multiply_vect_and_matrix(&rp_w, c2w, cam.rp);
			ft_vect_difference(&r.d_w, rp_w, r.o_w);
			ft_normalize_vect(&r.d_w);
			ft_trace(obj, r, &save);
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
