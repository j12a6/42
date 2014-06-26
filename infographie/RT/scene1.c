/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 21:44:15 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:32:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"

int		ft_init_cylinder(t_obj *obj)
{
	t_cyl	**lcyl;
	int		i;

	obj->nb[CYL] = 1;
	if (!(((t_cyl ***)obj->type)[CYL] = (t_cyl **)gmalloc(sizeof(t_cyl *)
															* obj->nb[CYL])))
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
	ft_init_color(&lcyl[0]->sf, 0, 0, 70);
	return (0);
}

int		ft_init_cone(t_obj *obj)
{
	t_con	**lcon;
	int		i;

	obj->nb[CON] = 2;
	if (!(((t_con ***)obj->type)[CON] = (t_con **)gmalloc(sizeof(t_con *)
															* obj->nb[CON])))
		return (-1);
	lcon = ((t_con ***)obj->type)[CON];
	i = -1;
	while (++i < obj->nb[CON])
	{
		if (!(lcon[i] = (t_con *)gmalloc(sizeof(t_con))))
			return (-1);
	}
	ft_init_vect(&lcon[0]->c, 4, 2, -2000);
	lcon[0]->cst = 0.1;
	lcon[0]->flag = 'y';
	ft_init_color(&lcon[0]->sf, 70, 0, 0);
	ft_init_vect(&lcon[1]->c, -8, -2, -2000);
	lcon[1]->cst = 0.1;
	lcon[1]->flag = 'x';
	ft_init_color(&lcon[1]->sf, 8, 35, 56);
	return (0);
}

int		ft_scene1(t_obj *obj)
{
	if (ft_init_sphere1(obj) == -1)
		return (-1);
	if (ft_init_cone(obj) == -1)
		return (-1);
	if (ft_init_cylinder(obj) == -1)
		return (-1);
	if (ft_init_disk1(obj) == -1)
		return (-1);
	if (ft_init_plane1(obj) == -1)
		return (-1);
	return (0);
}
