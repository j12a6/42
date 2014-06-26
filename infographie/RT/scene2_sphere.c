/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:08:49 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 23:17:05 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_init_sphere2_2(t_sph **lsph)
{
	ft_init_vect(&lsph[0]->c, -3, 0, -1500);
	lsph[0]->r = 0.0001;
	ft_init_color(&lsph[0]->sf, 255, 255, 255);
	ft_init_color(&lsph[0]->em, 255, 255, 255);
	ft_init_vect(&lsph[1]->c, 0, 2, -3980);
	lsph[1]->r = 0.1;
	ft_init_color(&lsph[1]->sf, 120, 120, 120);
	ft_init_color(&lsph[1]->em, 0, 0, 0);
	ft_init_vect(&lsph[2]->c, 0, -2, -3980);
	lsph[2]->r = 1;
	ft_init_color(&lsph[2]->sf, 20, 70, 0);
	ft_init_color(&lsph[2]->em, 0, 0, 0);
	ft_init_vect(&lsph[3]->c, 5, 2, -3980);
	lsph[3]->r = 0.7;
	ft_init_color(&lsph[3]->sf, 120, 0, 0);
	ft_init_color(&lsph[3]->em, 0, 0, 0);
	ft_init_vect(&lsph[4]->c, 7, -6, -2000);
	lsph[4]->r = 2;
	ft_init_color(&lsph[4]->sf, 20, 10, 80);
	ft_init_color(&lsph[4]->em, 0, 0, 0);
	ft_init_vect(&lsph[5]->c, 0, -7, -2005);
	lsph[5]->r = 1.2;
	ft_init_color(&lsph[5]->sf, 50, 50, 0);
	ft_init_color(&lsph[5]->em, 0, 0, 0);
}

void	ft_init_sphere2_3(t_sph **lsph)
{
	ft_init_vect(&lsph[6]->c, 8.5, -7.5, -1997);
	lsph[6]->r = 0.7;
	ft_init_color(&lsph[6]->sf, 0, 80, 80);
	ft_init_color(&lsph[6]->em, 0, 0, 0);
	ft_init_vect(&lsph[7]->c, 5.8, -5.7, -1998.35);
	lsph[7]->r = 0.2;
	ft_init_color(&lsph[7]->sf, 10, 10, 30);
	ft_init_color(&lsph[7]->em, 0, 0, 0);
	ft_init_vect(&lsph[8]->c, 7, -5.7, -1998);
	lsph[8]->r = 0.2;
	ft_init_color(&lsph[8]->sf, 10, 10, 30);
	ft_init_color(&lsph[8]->em, 0, 0, 0);
	ft_init_vect(&lsph[9]->c, 6, -2, -3980);
	lsph[9]->r = 0.05;
	ft_init_color(&lsph[9]->sf, 120, 120, 120);
	ft_init_color(&lsph[9]->em, 0, 0, 0);
	ft_init_vect(&lsph[10]->c, 0, -5.5, -3980);
	lsph[10]->r = 0.05;
	ft_init_color(&lsph[10]->sf, 120, 120, 120);
	ft_init_color(&lsph[10]->em, 0, 0, 0);
	ft_init_vect(&lsph[11]->c, 2, -6, -3980);
	lsph[11]->r = 0.08;
	ft_init_color(&lsph[11]->sf, 120, 120, 120);
	ft_init_color(&lsph[11]->em, 0, 0, 0);
}

void	ft_init_sphere2_4(t_sph **lsph)
{
	ft_init_vect(&lsph[12]->c, 8, 1, -3980);
	lsph[12]->r = 0.07;
	ft_init_color(&lsph[12]->sf, 120, 120, 120);
	ft_init_color(&lsph[12]->em, 0, 0, 0);
	ft_init_vect(&lsph[13]->c, 0.1, -6.8, -2003.4);
	lsph[13]->r = 0.15;
	ft_init_color(&lsph[13]->sf, 20, 20, 0);
	ft_init_color(&lsph[13]->em, 0, 0, 0);
	ft_init_vect(&lsph[14]->c, 0.7, -6.8, -2004);
	lsph[14]->r = 0.15;
	ft_init_color(&lsph[14]->sf, 20, 20, 0);
	ft_init_color(&lsph[14]->em, 0, 0, 0);
	ft_init_vect(&lsph[15]->c, -3, -1.8, -599);
	lsph[15]->r = 0.02;
	ft_init_color(&lsph[15]->sf, 120, 120, 120);
	ft_init_color(&lsph[15]->em, 0, 0, 0);
	ft_init_vect(&lsph[16]->c, -3.1, -0.8, -598);
	lsph[16]->r = 0.013;
	ft_init_color(&lsph[16]->sf, 120, 120, 120);
	ft_init_color(&lsph[16]->em, 0, 0, 0);
	ft_init_vect(&lsph[17]->c, -2.9, 2, -599);
	lsph[17]->r = 0.016;
	ft_init_color(&lsph[17]->sf, 120, 120, 120);
	ft_init_color(&lsph[17]->em, 0, 0, 0);
}

void	ft_init_sphere2_5(t_sph **lsph)
{
	ft_init_vect(&lsph[18]->c, -2.9, 0.7, -599);
	lsph[18]->r = 0.025;
	ft_init_color(&lsph[18]->sf, 120, 120, 120);
	ft_init_color(&lsph[18]->em, 0, 0, 0);
	ft_init_vect(&lsph[19]->c, -3, 0.5, -598);
	lsph[19]->r = 0.25;
	ft_init_color(&lsph[19]->sf, 0, 50, 120);
	ft_init_color(&lsph[19]->em, 0, 0, 0);
}

int		ft_init_sphere2(t_obj *obj)
{
	t_sph		**lsph;
	int			i;

	obj->nb[SPH] = 20;
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
	ft_init_sphere2_2(lsph);
	ft_init_sphere2_3(lsph);
	ft_init_sphere2_4(lsph);
	ft_init_sphere2_5(lsph);
	return (0);
}
