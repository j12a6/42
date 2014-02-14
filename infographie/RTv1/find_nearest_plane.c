/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:57:11 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/13 20:32:36 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "libft.h"

double		ft_is_in_plane(t_cam cam, t_plan plan)
{
	double		sol;
	t_v			vect;

	if (ft_dot_product(cam.d, plan.n) == 0.0)
		return (-1);
	vect = ft_diff_vect(plan.p, cam.e);
	sol = ft_dot_product(vect, plan.n) / ft_dot_product(cam.d, plan.n);
	if (sol <= 0)
		return (-1);
	return (sol);
}

double		ft_find_nearest_plane(int *ind, t_cam cam, t_pl *pl)
{
	t_pl		*move;
	int			i;
	double		dist;
	double		min;

	i = 0;
	move = pl;
	if (!move)
		return (-1);
	min = ft_is_in_plane(cam, move->plan);
	*ind = i;
	++i;
	while ((move = move->next))
	{
		dist = ft_is_in_plane(cam, move->plan);
		if (dist != -1 && (min == -1 || min > dist))
		{
			min = dist;
			*ind = i;
		}
		++i;
	}
	return (min);
}
