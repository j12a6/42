/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_a_cone.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:45:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 21:14:08 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_find_coeff(t_r *r, t_v *c, t_con *con)
{
	if (con->flag == 'x')
		ft_init_vect(c, r->d_w.y * r->d_w.y + r->d_w.z * r->d_w.z - con->cst
					* r->d_w.x * r->d_w.x,
					2 * (r->o_w.y * r->d_w.y + r->o_w.z * r->d_w.z - con->cst
						* r->o_w.x * r->d_w.x),
					r->o_w.y * r->o_w.y + r->o_w.z * r->o_w.z - con->cst
					* r->o_w.x * r->o_w.x);
	else if (con->flag == 'y')
		ft_init_vect(c, r->d_w.x * r->d_w.x + r->d_w.z * r->d_w.z - con->cst
					* r->d_w.y * r->d_w.y,
					2 * (r->o_w.x * r->d_w.x + r->o_w.z * r->d_w.z - con->cst
						* r->o_w.y * r->d_w.y),
					r->o_w.x * r->o_w.x + r->o_w.z * r->o_w.z - con->cst
					* r->o_w.y * r->o_w.y);
	else if (con->flag == 'z')
		ft_init_vect(c, r->d_w.y * r->d_w.y + r->d_w.x * r->d_w.x - con->cst
					* r->d_w.z * r->d_w.z,
					2 * (r->o_w.y * r->d_w.y + r->o_w.x * r->d_w.x - con->cst
						* r->o_w.z * r->d_w.z),
					r->o_w.y * r->o_w.y + r->o_w.x * r->o_w.x - con->cst
					* r->o_w.z * r->o_w.z);
}

int				ft_intersect_a_cone(t_r *r, void *data)
{
	t_con	*con;
	t_r		new_r;
	t_v		coeff;

	con = (t_con *)data;
	new_r = *r;
	ft_vect_difference(&new_r.o_w, r->o_w, con->c);
	ft_find_coeff(&new_r, &coeff, con);
	if (ft_nearest_solution(coeff.x, coeff.y, coeff.z, &new_r) == -1)
		return (-1);
	if (new_r.t1 < 0)
		return (-1);
	if (new_r.t0 < 0)
		new_r.t0 = new_r.t1;
	r->t0 = new_r.t0;
	r->t1 = new_r.t1;
	return (0);
}
