/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:06:06 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 22:16:59 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_init_plane1_2(t_pla **lpla)
{
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
}

int		ft_init_plane1(t_obj *obj)
{
	t_pla		**lpla;
	int			i;

	obj->nb[PLA] = 5;
	if (!(((t_pla ***)obj->type)[PLA] = (t_pla **)gmalloc(sizeof(t_pla *)
															* obj->nb[PLA])))
		return (-1);
	lpla = ((t_pla ***)obj->type)[PLA];
	i = -1;
	while (++i < obj->nb[PLA])
	{
		if (!(lpla[i] = (t_pla *)gmalloc(sizeof(t_pla))))
			return (-1);
	}
	ft_init_plane1_2(lpla);
	return (0);
}
