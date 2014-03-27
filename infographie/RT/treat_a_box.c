/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 17:34:39 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 12:02:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_treat_a_box(void *data, t_c *color, t_obj *obj, t_r *r)
{
	t_box		*box;
	t_obj		*obj2;
	t_r			*r2;

	obj2 = obj;
	obj = obj2;
	r2 = r;
	r = r2;
	box = (t_box *)data;
	*color = box->sf;
	return (0);
}
