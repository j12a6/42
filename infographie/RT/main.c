/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:02:27 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/17 20:23:00 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

int		main(int ac, char **av)
{
	double	i;
	double	j;
	t_r		r;
	t_v		ro_c;
	t_v		rp_c;
	t_v		rp_w;
	double	**c2w;
	t_b		cam;
	t_v		trans;

	ft_init_vect(&(cam.vx), 1.0, 0.0, 0.0);
	ft_init_vect(&(cam.vy), 0.0, 1.0, 0.0);
	ft_init_vect(&(cam.vz), 0.0, 0.0, 1.0);
	ft_init_vect(&ro_c, 0.0, 0.0, 0.0);
//	ft_init_vect(&ro_w, 0.0, 0.0, 0.0);
	ft_init_vect(&trans, 0.0, 0.0, 0.0);
	if (ac != 2 || !av[2])
		return (ft_error("Please choose a scene", "", -1));	
	if (!(c2w = ft_init_matrix(cam.vx, cam.vy, cam.vz, trans)))
		return (-1);
	j = -1;
	while  (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			ft_find_pixel_pos_on_screen(&rp_c, i, j);
//			ft_multiply_vect_and_matrix(&r.o, c2w, ro_c);
			r.o = ro_c;//delete ligne au dessus
			ft_multiply_vect_and_matrix(&rp_w, c2w, rp_c);
			ft_vect_difference(&r.d, rp_w, r.o);
			ft_normalize_vect(&r.d);
		}
	}
	return (0);
}
