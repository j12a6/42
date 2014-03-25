/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_equ_quadratic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 09:42:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/25 10:04:19 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

int					ft_nearest_solution(double a, double b, double c, t_r *r)
{
	double		delta;
	double		q;

	delta = b * b - 4.0 * a * c;
	if (delta < 0)
		return (-1);
	else if (delta == 0)
	{
		r->t0 = (-0.5 * b) / a;
		r->t1 = r->t0;
	}
	else
	{
		q = (b > 0) ? -0.5 * (b + sqrt(delta)) : -0.5 * (b - sqrt(delta));
		r->t0 = q / a;
		r->t1 = c / q;
	}
	if (r->t0 > r->t1)
		ft_swap(&r->t0, &r->t1);
	return (0);
}
