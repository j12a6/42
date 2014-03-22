/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 16:26:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/22 18:19:00 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

int		ft_init_object_structure(t_obj *obj)
{
	int		i;

	if (!(obj->pixel = (t_c **)gmalloc(sizeof(t_c *) * HEIGHT))
		|| !(obj->type = (void ***)gmalloc(sizeof(void **) * NB_TYPE))
		|| !(obj->nb = (int *)gmalloc(sizeof(int) * NB_TYPE)))
		return (-1);
	i = -1;
	while (++i < HEIGHT)
	{
		if (!(obj->pixel[i] = (t_c *)gmalloc(sizeof(t_c) * WIDTH)))
			return (-1);
	}
	i = -1;
	while (++i < NB_TYPE)
		obj->nb[i] = 0;
	obj->intersect[0] = ft_intersect_a_box;
	obj->intersect[1] = ft_intersect_a_sphere;
	obj->intersect[2] = ft_intersect_a_disk;
	obj->intersect[3] = ft_intersect_a_plane;
	obj->treatment[0] = ft_treat_a_box;
	obj->treatment[1] = ft_treat_a_sphere;
	obj->treatment[2] = ft_treat_a_disk;
	obj->treatment[3] = ft_treat_a_plane;
	ft_init_color(&(obj->bg_clr), 100, 100, 100);
	return (0);
}


#include <stdio.h>



int		ft_do_scene(t_obj *obj)
{
	t_sph	**lsph;
	int		i;

	obj->nb[SPH] = 2;
	if (!(((t_sph ***)obj->type)[SPH]
		  = (t_sph **)gmalloc(sizeof(t_sph *) * obj->nb[SPH])))
		return (-1);
	lsph = ((t_sph ***)obj->type)[SPH];
	i = -1;
	while (++i < obj->nb[SPH])
	{
		if (!(lsph[i] = (t_sph *)gmalloc(sizeof(t_sph))))
			return (-1);
	}
	lsph[++i] = NULL;
	ft_init_vect(&lsph[0]->c, 0, 0, -10);
	lsph[0]->r = 5;
	ft_init_color(&lsph[0]->sf, 50, 0, 0);
	ft_init_color(&lsph[0]->em, 0, 0, 0);
	lsph[0]->trsp = 0;
	lsph[0]->refl = 100;
	lsph[0]->ior = 1.2;
	ft_init_vect(&lsph[1]->c, 0, 5, 2);
	lsph[1]->r = 1.5;
	ft_init_color(&lsph[1]->sf, 0, 100, 0);
	ft_init_color(&lsph[1]->em, 0, 100, 0);
	lsph[1]->trsp = 0;
	lsph[1]->refl = 100;
	lsph[1]->ior = 1.2;
	return (0);
}
