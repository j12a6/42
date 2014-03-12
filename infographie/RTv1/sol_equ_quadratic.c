/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_equ_quadratic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 09:42:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 18:14:51 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

static double		ft_discriminant(double a, double b, double c)
{
	return (pow(b, 2) - 4.0 * a * c);
}

double				ft_nearest_solution(double a, double b, double c)
{
	double		sol1;
	double		sol2;
	double		delta;

	delta = ft_discriminant(a, b, c);
	if (delta < 0.0)
		return (-1);
	else if (delta == 0.0)
		return (-b / (2.0 * a));
	else
	{
		sol1 = (-b + sqrt(delta)) / (2.0 * a);
		sol2 = (-b - sqrt(delta)) / (2.0 * a);
		if (sol1 < sol2)
			return (sol1);
		else
			return (sol2);
	}
}
