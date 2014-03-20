/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_disk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 17:40:53 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/20 17:41:20 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "rt.h"

int		ft_treat_a_disk(t_r *r, void *data, t_c *color, t_obj obj)
{
	t_box	*box;
	t_box	*box1;
	t_r		r1;
	t_c		color1;
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
