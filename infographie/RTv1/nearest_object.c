/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:32:07 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/13 18:17:56 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

void		ft_find_nearest_object(t_sol *sol, t_mlx *mlx, t_cam cam)
{
	double		dist;
	double		min;
	int			ind;

	sol->c = '-';
	if ((min = ft_find_nearest_sphere(&ind, cam, mlx->obj.sl)) != -1)
	{
		sol->ind = ind;
		sol->c = 's';
	}
	dist = ft_find_nearest_plane(&ind, cam, mlx->obj.pl);
	if (dist != -1 && (min == -1 || min > dist))
	{
		min = dist;
		sol->ind = ind;
		sol->c = 'p';
	}
}
