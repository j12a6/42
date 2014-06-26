/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 16:26:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 23:11:53 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

int		ft_scene2(t_obj *obj)
{
	if (ft_init_sphere2(obj) == -1)
		return (-1);
	if (ft_init_plane2(obj) == -1)
		return (-1);
	if (ft_init_disk2(obj) == -1)
		return (-1);
	return (0);
}
