/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_orthonormal_basis.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert   <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 13:45:23 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 18:16:44 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

static void		ft_transform_in_unit_vect(t_v *vect)
{
	double	norm;

	norm = ft_vect_norm(*vect);
	(*vect).x = (*vect).x / norm;
	(*vect).y = (*vect).y / norm;
	(*vect).z = (*vect).z / norm;
}

static void		ft_find_orthogonal_vect(t_v *vect, t_v *ortho_vect)
{
	(*ortho_vect).x = -(*vect).z / ((*vect).x + (*vect).y);
	(*ortho_vect).y = (*ortho_vect).x;
	(*ortho_vect).z = 1;
}

void			ft_create_orthonormal_basis(t_v *u, t_v *v, t_v *w)
{
	ft_find_orthogonal_vect(w, u);
	*v = ft_cross_product(*w, *u);
	ft_transform_in_unit_vect(u);
	ft_transform_in_unit_vect(v);
	ft_transform_in_unit_vect(w);
}
