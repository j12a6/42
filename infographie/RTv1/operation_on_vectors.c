/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_on_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 09:45:39 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 18:15:07 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

t_v			ft_diff_vect(t_v vect1, t_v vect2)
{
	t_v		vect;

	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return (vect);
}

double		ft_dot_product(t_v vect1, t_v vect2)
{
	double	result;

	result = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (result);
}

t_v			ft_cross_product(t_v vect1, t_v vect2)
{
	t_v		vect;

	vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
	vect.y = -(vect1.x * vect2.z - vect1.z * vect2.x);
	vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
	return (vect);
}

void		ft_save_transfer_matrix(double ***mat, t_base *b, t_v w)
{
	t_base		base;
	t_v			u;
	t_v			v;

	ft_init_vect(&(base.v1), 1, 0, 0);
	ft_init_vect(&(base.v2), 0, 1, 0);
	ft_init_vect(&(base.v3), 0, 0, 1);
	ft_create_orthonormal_basis(&u, &v, &w);
	ft_init_vect(&(b->v1), u.x, u.y, u.z);
	ft_init_vect(&(b->v2), v.x, v.y, v.z);
	ft_init_vect(&(b->v3), w.x, w.y, w.z);
	(*mat)[0][0] = ft_dot_product(u, base.v1);
	(*mat)[0][1] = ft_dot_product(u, base.v2);
	(*mat)[0][2] = ft_dot_product(u, base.v3);
	(*mat)[1][0] = ft_dot_product(v, base.v1);
	(*mat)[1][1] = ft_dot_product(v, base.v2);
	(*mat)[1][2] = ft_dot_product(v, base.v3);
	(*mat)[2][0] = ft_dot_product(w, base.v1);
	(*mat)[2][1] = ft_dot_product(w, base.v2);
	(*mat)[2][2] = ft_dot_product(w, base.v3);
}

void		ft_save_transfer_matrix_inverse(double ***mat, t_base *b, t_v w)
{
	t_base		base;
	t_v			u;
	t_v			v;

	ft_init_vect(&(base.v1), 1, 0, 0);
	ft_init_vect(&(base.v2), 0, 1, 0);
	ft_init_vect(&(base.v3), 0, 0, 1);
	ft_create_orthonormal_basis(&u, &v, &w);
	ft_init_vect(&(b->v1), u.x, u.y, u.z);
	ft_init_vect(&(b->v2), v.x, v.y, v.z);
	ft_init_vect(&(b->v3), w.x, w.y, w.z);
	(*mat)[0][0] = ft_dot_product(base.v1, u);
	(*mat)[0][1] = ft_dot_product(base.v1, v);
	(*mat)[0][2] = ft_dot_product(base.v1, w);
	(*mat)[1][0] = ft_dot_product(base.v2, u);
	(*mat)[1][1] = ft_dot_product(base.v2, v);
	(*mat)[1][2] = ft_dot_product(base.v2, w);
	(*mat)[2][0] = ft_dot_product(base.v3, u);
	(*mat)[2][1] = ft_dot_product(base.v3, v);
	(*mat)[2][2] = ft_dot_product(base.v3, w);
}
