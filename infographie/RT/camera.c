/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:42:05 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/18 17:40:30 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

double	*ft_set_fov_angle(void)
{
	static double	fov = M_PI_2;

	return (&fov);
}

int		ft_find_pixel_pos_on_screen(t_v *rp_c, int i, int j)
{
	double		fov;
	double		ratio;

	ratio = WIDTH / HEIGHT;
	fov = *ft_set_fov_angle();
	rp_c->x = (2 * ((i + 0.5) / WIDTH) - 1) * ratio * tan(fov / 2.0);
	rp_c->y = (1 - 2 * ((j + 0.5) / HEIGHT)) * tan(fov / 2.0);
	rp_c->z = -1;
	return (0);
}
