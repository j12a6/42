/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1_disk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:03:29 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:16:32 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_init_disk1_2(t_dis **ldis)
{
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
}

int		ft_init_disk1(t_obj *obj)
{
	t_dis		**ldis;
	int			i;

	obj->nb[DIS] = 4;
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
	ft_init_disk1_2(ldis);
	return (0);
}
