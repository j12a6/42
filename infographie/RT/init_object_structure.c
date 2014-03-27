/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 16:26:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 11:39:02 by jaubert          ###   ########.fr       */
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
	obj->intersect[2] = ft_intersect_a_plane;
	obj->intersect[3] = ft_intersect_a_disk;
	obj->treatment[0] = ft_treat_a_box;
	obj->treatment[1] = ft_treat_a_sphere;
	obj->treatment[2] = ft_treat_a_plane;
	obj->treatment[3] = ft_treat_a_disk;
	ft_init_color(&(obj->bg_clr), 0, 0, 0);
	return (0);
}


#include <stdio.h>

int		ft_init_cyl2w(int ***cyl2w, double rotx, double roty, double rotz)
{
	int		i;

	if (!(*cyl2w = (int **)gmalloc(sizeof(int *) * 3)))
		return (-1);
	i = -1;
	while (++i < 3)
	{
		if (!((*cyl2w)[i] = (t_cyl *)gmalloc(sizeof(int) * 3)))
			return (-1);
	}
	cyl2w[0][0] = 1;
	cyl2w[1][0] = 1;
	cyl2w[2][0] = 1;
	cyl2w[0][1] = 1;
	cyl2w[1][1] = 1;
	cyl2w[2][1] = 1;
	cyl2w[0][2] = 1;
	cyl2w[1][2] = 1;
	cyl2w[2][2] = 1;
	


	return (0);
}

int		ft_do_scene(t_obj *obj)
{
	t_sph	**lsph;
	t_box	**lbox;
	t_pla	**lpla;
	t_dis	**ldis;
	int		i;

	obj->nb[SPH] = 4;
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
	ft_init_vect(&lsph[0]->c, 0, 0, -2000);
	lsph[0]->r = 2;
	ft_init_color(&lsph[0]->sf, 80, 0, 0);
	ft_init_color(&lsph[0]->em, 0, 0, 0);
	lsph[0]->trsp = 0;
	lsph[0]->refl = 0;
	lsph[0]->ior = 0;
	ft_init_vect(&lsph[1]->c, -7, -7, -1995);
	lsph[1]->r = 3;
	ft_init_color(&lsph[1]->sf, 20, 100, 20);
	ft_init_color(&lsph[1]->em, 255, 255, 255);
	lsph[1]->trsp = 0;
	lsph[1]->refl = 0;
	lsph[1]->ior = 0;
	ft_init_vect(&lsph[2]->c, -2, 0, -2000);
	lsph[2]->r = 1;
	ft_init_color(&lsph[2]->sf, 0, 0, 80);
	ft_init_color(&lsph[2]->em, 0, 0, 0);
	lsph[2]->trsp = 0;
	lsph[2]->refl = 0;
	lsph[2]->ior = 0;
	ft_init_vect(&lsph[3]->c, 3, 3, -2000);
	lsph[3]->r = 3;
	ft_init_color(&lsph[3]->sf, 255, 255, 255);
	ft_init_color(&lsph[3]->em, 255, 255, 255);
	lsph[3]->trsp = 0;
	lsph[3]->refl = 0;
	lsph[3]->ior = 0;

	obj->nb[BOX] = 1;
	if (!(((t_box ***)obj->type)[BOX]
		  = (t_box **)gmalloc(sizeof(t_box *) * obj->nb[BOX])))
		return (-1);
	lbox = ((t_box ***)obj->type)[BOX];
	i = -1;
	while (++i < obj->nb[BOX])
	{
		if (!(lbox[i] = (t_box *)gmalloc(sizeof(t_box))))
			return (-1);
	}
	lbox[0]->xmin = -8;
	lbox[0]->xmax = -10;
	lbox[0]->ymin = 4;
	lbox[0]->ymax = 6;
	lbox[0]->zmin = -2002;
	lbox[0]->zmax = -2006;
	ft_init_color(&lbox[0]->sf, 100, 0, 100);

	obj->nb[PLA] = 1;
	if (!(((t_pla ***)obj->type)[PLA]
		  = (t_pla **)gmalloc(sizeof(t_pla *) * obj->nb[PLA])))
		return (-1);
	lpla = ((t_pla ***)obj->type)[PLA];
	i = -1;
	while (++i < obj->nb[PLA])
	{
		if (!(lpla[i] = (t_pla *)gmalloc(sizeof(t_pla))))
			return (-1);
	}
	ft_init_vect(&lpla[0]->c, 2, 10, -2000);
	ft_init_vect(&lpla[0]->n, -1, 0, 0);
	ft_init_color(&lpla[0]->sf, 0, 80, 80);

	obj->nb[DIS] = 1;
	if (!(((t_dis ***)obj->type)[DIS]
		  = (t_dis **)gmalloc(sizeof(t_dis *) * obj->nb[DIS])))
		return (-1);
	ldis = ((t_dis ***)obj->type)[DIS];
	i = -1;
	while (++i < obj->nb[DIS])
	{
		if (!(ldis[i] = (t_dis *)gmalloc(sizeof(t_dis))))
			return (-1);
	}
	ft_init_vect(&ldis[0]->c, -4, 2, -2000);
	ldis[0]->r = 1;
	ft_init_vect(&ldis[0]->n, 0, -1, -1);
	ft_init_color(&ldis[0]->sf, 80, 0, 80);
	
	obj->nb[SCYL] = 1;
	if (!(((t_cyl ***)obj->type)[CYL]
		  = (t_cyl **)gmalloc(sizeof(t_cyl *) * obj->nb[CYL])))
		return (-1);
	lcyl = ((t_cyl ***)obj->type)[CYL];
	i = -1;
	while (++i < obj->nb[CYL])
	{
		if (!(lcyl[i] = (t_cyl *)gmalloc(sizeof(t_cyl))))
			return (-1);
	}
	ft_init_vect(&lcyl[0]->c, -8, 0, -2000);
	ft_init_vect(&lcyl[0]->a, 0, 1, 0);
	lcyl[0]->r = 1;
	ft_init_color(&lcyl[0]->sf, 80, 0, 80);
	return (0);
}
