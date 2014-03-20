/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:02:27 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/20 17:48:44 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
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
		while (++j < obj.nb[i])
		{
			if (obj.intersect[i](r, (obj.type)[i][j]) == 0)
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
		return (obj.bg_clr);
	obj.treatment[save->i](r, (obj.type)[save->i][save->j], &color, obj);
	return (color);
}


int			raytracer(t_obj *obj, t_cam cam)
{
	int			i;
	int			j;
	t_r			r;
	t_v			rp_w;
	double		**c2w;
	t_save		save;
	t_obj		new_obj;

	new_obj = *obj;
	ft_init_vect(&cam.ro, 0.0, 0.0, 0.0);
	if (!(c2w = ft_init_matrix(cam.b.vx, cam.b.vy, cam.b.vz, cam.trans)))
		return (-1);
	//ft_mult_vect_by_matrix(&r.o, c2w, ro_c);
	r.o_w = cam.ro;//delete ligne au dessus
	j = -1;
	while  (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			save.i = -1;
			save.j = -1;
			new_obj.depth = 0;
			ft_find_pixel_pos_on_screen(&cam.rp, i, j);
			ft_mult_vect_by_matrix(&rp_w, c2w, cam.rp);
			ft_vect_difference(&r.d_w, rp_w, r.o_w);
			ft_normalize_vect(&r.d_w);
			obj->pixel[j][i] = ft_trace(new_obj, &r, &save);
			// attention fonction au dessus, pas sur de & de 'r'
		}
	}
	return (0);
}

int		key_hook(int key, t_mlx *mlx)
{
	t_mlx  plouf;

	plouf = *mlx;
	*mlx = plouf;
	if (key == 65307)
	{
		mlx = NULL;
		exit(0);
	}
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	ft_draw(mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_cam		cam;
	t_mlx		mlx;

	if (ac != 2 || !av[1])
		return (ft_error("Please choose one scene", "", -1));
	ft_init_array_of_fct_pointer(&mlx.obj);
	/*	if (ft_parser(av[1], &mlx.obj) == -1)
		return (-1);*/
	ft_init_vect(&(cam.b.vx), 1.0, 0.0, 0.0);
	ft_init_vect(&(cam.b.vy), 0.0, 1.0, 0.0);
	ft_init_vect(&(cam.b.vz), 0.0, 0.0, 1.0);
	ft_init_vect(&cam.trans, 0.0, 0.0, 0.0);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "RT");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.i.data = mlx_get_data_addr(mlx.img, &(mlx.i.bpp), &(mlx.i.sl),
			&(mlx.i.endian));
	mlx_key_hook(mlx.win, key_hook, &mlx);
	raytracer(&mlx.obj, cam);
	mlx_expose_hook(mlx.win, expose_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
