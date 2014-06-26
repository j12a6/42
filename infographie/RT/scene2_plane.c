/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene2_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 22:06:06 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 23:12:54 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_init_plane2_2(t_pla **lpla)
{
	ft_init_vect(&lpla[0]->c, 0, 0, -4000);
	ft_init_vect(&lpla[0]->n, 0, 0, 1);
	ft_normalize_vect(&lpla[0]->n);
	ft_init_color(&lpla[0]->sf, 25, 25, 25);
	ft_init_vect(&lpla[1]->c, 0, 7, -2000);
	ft_init_vect(&lpla[1]->n, 0, -1, 0);
	ft_normalize_vect(&lpla[1]->n);
	ft_init_color(&lpla[1]->sf, 60, 60, 60);
	ft_init_vect(&lpla[2]->c, 0, -9, -2000);
	ft_init_vect(&lpla[2]->n, 0, 1, 0);
	ft_normalize_vect(&lpla[2]->n);
	ft_init_color(&lpla[2]->sf, 60, 60, 60);
	ft_init_vect(&lpla[3]->c, -4, 0, -2000);
	ft_init_vect(&lpla[3]->n, 1, 0, 0);
	ft_normalize_vect(&lpla[3]->n);
	ft_init_color(&lpla[3]->sf, 70, 70, 70);
	ft_init_vect(&lpla[4]->c, 12, 0, -2000);
	ft_init_vect(&lpla[4]->n, -1, 0, 0);
	ft_normalize_vect(&lpla[4]->n);
	ft_init_color(&lpla[4]->sf, 70, 70, 70);
}

int		ft_init_plane2(t_obj *obj)
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
	ft_init_plane2_2(lpla);
	return (0);
}
