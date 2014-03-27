/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 16:26:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 20:22:21 by jaubert          ###   ########.fr       */
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
	obj->intersect[4] = ft_intersect_a_cylinder;
	obj->intersect[5] = ft_intersect_a_cone;
	obj->treatment[0] = ft_treat_a_box;
	obj->treatment[1] = ft_treat_a_sphere;
	obj->treatment[2] = ft_treat_a_plane;
	obj->treatment[3] = ft_treat_a_disk;
	obj->treatment[4] = ft_treat_a_cylinder;
	obj->treatment[5] = ft_treat_a_cone;
	ft_init_color(&(obj->bg_clr), 0, 0, 0);
	return (0);
}


#include <stdio.h>



int		ft_do_scene(t_obj *obj)
{
	t_sph	**lsph;
	t_pla	**lpla;
	t_dis	**ldis;
	t_con	**lcon;
	t_cyl	**lcyl;
	int		i;

	obj->nb[SPH] = 5;
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
	ft_init_vect(&lsph[0]->c, 0.3, 1, -2000);
	lsph[0]->r = 2;
	ft_init_color(&lsph[0]->sf, 80, 0, 0);
	ft_init_color(&lsph[0]->em, 0, 0, 0);
	lsph[0]->trsp = 0;
	lsph[0]->refl = 0;
	lsph[0]->ior = 0;
	ft_init_vect(&lsph[1]->c, -7, -7, -1995);
	lsph[1]->r = 3;
	ft_init_color(&lsph[1]->sf, 20, 100, 20);
	ft_init_color(&lsph[1]->em, 0, 0, 0);
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
	ft_init_vect(&lsph[3]->c, 3, 0, -1990);
	lsph[3]->r = 0.5;
	ft_init_color(&lsph[3]->sf, 255, 255, 255);
	ft_init_color(&lsph[3]->em, 255, 255, 255);
	lsph[3]->trsp = 0;
	lsph[3]->refl = 0;
	lsph[3]->ior = 0;
	ft_init_vect(&lsph[4]->c, -6, -3, -2000);
	lsph[4]->r = 2;
	ft_init_color(&lsph[4]->sf, 0, 80, 80);
	ft_init_color(&lsph[4]->em, 0, 0, 0);
	lsph[4]->trsp = 0;
	lsph[4]->refl = 0;
	lsph[4]->ior = 0;

	obj->nb[PLA] = 5;
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
	ft_init_vect(&lpla[0]->c, 0, 0, -2015);
	ft_init_vect(&lpla[0]->n, 0, 0, 1);
	ft_normalize_vect(&lpla[0]->n);
	ft_init_color(&lpla[0]->sf, 50, 50, 50);

	ft_init_vect(&lpla[1]->c, 0, 10, -2000);
	ft_init_vect(&lpla[1]->n, 0, -1, 0);
	ft_normalize_vect(&lpla[1]->n);
	ft_init_color(&lpla[1]->sf, 10, 10, 80);

	ft_init_vect(&lpla[2]->c, 0, -10, -2000);
	ft_init_vect(&lpla[2]->n, 0, 1, 0);
	ft_normalize_vect(&lpla[2]->n);
	ft_init_color(&lpla[2]->sf, 10, 10, 80);

	ft_init_vect(&lpla[3]->c, -15, 0, -2000);
	ft_init_vect(&lpla[3]->n, 1, 0, 0);
	ft_normalize_vect(&lpla[3]->n);
	ft_init_color(&lpla[3]->sf, 80, 10, 10);

	ft_init_vect(&lpla[4]->c, 15, 0, -2000);
	ft_init_vect(&lpla[4]->n, -1, 0, 0);
	ft_normalize_vect(&lpla[4]->n);
	ft_init_color(&lpla[4]->sf, 80, 10, 10);


	obj->nb[DIS] = 4;
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
	ft_init_vect(&ldis[0]->n, 1, 1, 1);
	ft_normalize_vect(&ldis[0]->n);
	ft_init_color(&ldis[0]->sf, 80, 0, 80);

	ft_init_vect(&ldis[1]->c, -4, 2, -2000);
	ldis[1]->r = 1;
	ft_init_vect(&ldis[1]->n, 1, 0, 0.5);
	ft_normalize_vect(&ldis[1]->n);
	ft_init_color(&ldis[1]->sf, 20, 20, 80);

	ft_init_vect(&ldis[2]->c, -4, 2, -2000);
	ldis[2]->r = 1;
	ft_init_vect(&ldis[2]->n, 1, 0, 0.5);
	ft_normalize_vect(&ldis[2]->n);
	ft_init_color(&ldis[2]->sf, 20, 60, 80);

	ft_init_vect(&ldis[3]->c, -4, 2, -2000);
	ldis[3]->r = 1;
	ft_init_vect(&ldis[3]->n, 1, 0, 0.5);
	ft_normalize_vect(&ldis[3]->n);
	ft_init_color(&ldis[3]->sf, 20, 80, 80);

	obj->nb[CYL] = 1;
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
	ft_init_vect(&lcyl[0]->c, 5, 0, -2000);
	lcyl[0]->r = 1;
	lcyl[0]->flag = 'z';
	ft_init_color(&lcyl[0]->sf, 0, 0, 100);

	obj->nb[CON] = 1;
	if (!(((t_con ***)obj->type)[CON]
		  = (t_con **)gmalloc(sizeof(t_con *) * obj->nb[CON])))
		return (-1);
	lcon = ((t_con ***)obj->type)[CON];
	i = -1;
	while (++i < obj->nb[CON])
	{
		if (!(lcon[i] = (t_con *)gmalloc(sizeof(t_con))))
			return (-1);
	}
	ft_init_vect(&lcon[0]->c, 9, 2, -2001);
	lcon[0]->cst = 0.05;
	lcon[0]->flag = 'y';
	ft_init_color(&lcon[0]->sf, 80, 0, 0);
	return (0);
}
