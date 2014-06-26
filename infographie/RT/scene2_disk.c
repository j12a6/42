/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2_disk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:03:29 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 23:10:41 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_init_disk2_2(t_dis **ldis)
{
	ft_init_vect(&ldis[0]->c, 4, -1, -3990);
	ldis[0]->r = 7;
	ft_init_vect(&ldis[0]->n, 0, 0, -1);
	ft_normalize_vect(&ldis[0]->n);
	ft_init_color(&ldis[0]->sf, 10, 10, 10);
	ft_init_vect(&ldis[1]->c, -4.95, 0, -1000);
	ldis[1]->r = 3;
	ft_init_vect(&ldis[1]->n, 1, 0, 0);
	ft_normalize_vect(&ldis[1]->n);
	ft_init_color(&ldis[1]->sf, 0, 0, 0);
	ft_init_vect(&ldis[2]->c, 5, 2, -3980);
	ldis[2]->r = 1;
	ft_init_vect(&ldis[2]->n, 0.5, 1, 0.5);
	ft_normalize_vect(&ldis[2]->n);
	ft_init_color(&ldis[2]->sf, 80, 0, 0);
	ft_init_vect(&ldis[3]->c, 0, -2, -3980);
	ldis[3]->r = 1.4;
	ft_init_vect(&ldis[3]->n, -1, 0.3, 0.3);
	ft_normalize_vect(&ldis[3]->n);
	ft_init_color(&ldis[3]->sf, 10, 50, 0);
	ft_init_vect(&ldis[4]->c, 7, -5, -2000);
	ldis[4]->r = 2;
	ft_init_vect(&ldis[4]->n, 1, 0, 0.3);
	ft_normalize_vect(&ldis[4]->n);
	ft_init_color(&ldis[4]->sf, 20, 10, 50);
}

void	ft_init_disk2_3(t_dis **ldis)
{
	ft_init_vect(&ldis[5]->c, 0, -6.2, -2005);
	ldis[5]->r = 1;
	ft_init_vect(&ldis[5]->n, -1, 0, 0.4);
	ft_normalize_vect(&ldis[5]->n);
	ft_init_color(&ldis[5]->sf, 30, 30, 0);
	ft_init_vect(&ldis[6]->c, 8.5, -7, -1997);
	ldis[6]->r = 0.7;
	ft_init_vect(&ldis[6]->n, 1, 0, 0.3);
	ft_normalize_vect(&ldis[6]->n);
	ft_init_color(&ldis[6]->sf, 0, 50, 50);
	ft_init_vect(&ldis[7]->c, 6.6, -6.6, -1998.5);
	ldis[7]->r = 0.9;
	ft_init_vect(&ldis[7]->n, -0.1, 1, 0.5);
	ft_normalize_vect(&ldis[7]->n);
	ft_init_color(&ldis[7]->sf, 20, 10, 50);
	ft_init_vect(&ldis[8]->c, 0.4, -7.5, -2004.2);
	ldis[8]->r = 0.6;
	ft_init_vect(&ldis[8]->n, -0.2, 1, -0.5);
	ft_normalize_vect(&ldis[8]->n);
	ft_init_color(&ldis[8]->sf, 30, 30, 0);
	ft_init_vect(&ldis[9]->c, -3, 0, -600);
	ldis[9]->r = 3;
	ft_init_vect(&ldis[9]->n, 1, 0, 0.2);
	ft_normalize_vect(&ldis[9]->n);
	ft_init_color(&ldis[9]->sf, 0, 0, 0);
}

int		ft_init_disk2(t_obj *obj)
{
	t_dis		**ldis;
	int			i;

	obj->nb[DIS] = 11;
	if (!(((t_dis ***)obj->type)[DIS] = (t_dis **)gmalloc(sizeof(t_dis *)
															* obj->nb[DIS])))
		return (-1);
	ldis = ((t_dis ***)obj->type)[DIS];
	i = -1;
	while (++i < obj->nb[DIS])
	{
		if (!(ldis[i] = (t_dis *)gmalloc(sizeof(t_dis))))
			return (-1);
	}
	ft_init_disk2_2(ldis);
	ft_init_disk2_3(ldis);
	ft_init_vect(&ldis[10]->c, -3, 0.5, -598);
	ldis[10]->r = 0.32;
	ft_init_vect(&ldis[10]->n, 0.2, 1, 0.3);
	ft_normalize_vect(&ldis[10]->n);
	ft_init_color(&ldis[10]->sf, 0, 20, 80);
	return (0);
}
