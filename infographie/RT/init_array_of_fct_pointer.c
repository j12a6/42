/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array_of_fct_pointer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 16:26:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/20 16:36:29 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_init_array_of_fct_pointer(t_obj *obj)
{
	obj->intersect[0] = ft_intersect_a_box;
	obj->intersect[1] = ft_intersect_a_sphere;
	obj->intersect[2] = ft_intersect_a_disk;
	obj->intersect[3] = ft_intersect_a_plane;
	obj->treatment[0] = ft_treat_a_box;
	obj->treatment[1] = ft_treat_a_sphere;
	obj->treatment[2] = ft_treat_a_disk;
	obj->treatment[3] = ft_treat_a_plane;
	return (0);
}
