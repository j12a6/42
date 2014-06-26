/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:08:49 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:41:31 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_init_sphere1_2(t_sph **lsph)
{
	ft_init_vect(&lsph[0]->c, 0.3, 1, -2000);
	lsph[0]->r = 2;
	ft_init_color(&lsph[0]->sf, 70, 0, 0);
	ft_init_color(&lsph[0]->em, 0, 0, 0);
	ft_init_vect(&lsph[1]->c, -7, -7, -1995);
	lsph[1]->r = 3;
	ft_init_color(&lsph[1]->sf, 20, 70, 20);
	ft_init_color(&lsph[1]->em, 0, 0, 0);
	ft_init_vect(&lsph[2]->c, -2, 0, -2000);
	lsph[2]->r = 1;
	ft_init_color(&lsph[2]->sf, 0, 0, 80);
	ft_init_color(&lsph[2]->em, 0, 0, 0);
	ft_init_vect(&lsph[3]->c, 3, 0, -1990);
	lsph[3]->r = 0.5;
	ft_init_color(&lsph[3]->sf, 255, 255, 255);
	ft_init_color(&lsph[3]->em, 255, 255, 255);
	ft_init_vect(&lsph[4]->c, -6, -3, -2000);
	lsph[4]->r = 2;
	ft_init_color(&lsph[4]->sf, 0, 70, 70);
	ft_init_color(&lsph[4]->em, 0, 0, 0);
}

int		ft_init_sphere1(t_obj *obj)
{
	t_sph		**lsph;
	int			i;

	obj->nb[SPH] = 5;
	if (!(((t_sph ***)obj->type)[SPH] = (t_sph **)gmalloc(sizeof(t_sph *)
															* obj->nb[SPH])))
		return (-1);
	lsph = ((t_sph ***)obj->type)[SPH];
	i = -1;
	while (++i < obj->nb[SPH])
	{
		if (!(lsph[i] = (t_sph *)gmalloc(sizeof(t_sph))))
			return (-1);
	}
	ft_init_sphere1_2(lsph);
	return (0);
}
