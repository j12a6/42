/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 17:41:40 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/20 17:42:35 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_treat_a_plane(t_r *r, void *data, t_c *color, t_obj obj)
{
	t_box	*box;
	t_box	*box1;
	t_r	r1;
	t_c	color1;
	t_obj	obj1;

	box = (t_box *)data;
	box1 = box;
	box = box1;
	r1 = *r;
	*r = r1;
	color1 = *color;
	*color = color1;
	obj1 = obj;
	obj = obj1;
	return (0);
}
