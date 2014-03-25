/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 15:12:32 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/25 15:18:37 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "rt.h"

int		ft_draw(t_mlx *mlx)
{
	int		i;
	int		j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			mlx->i.data[0 + i * 4 + j * mlx->i.sl] = (mlx->obj.pixel[j][i]).b;
			mlx->i.data[1 + i * 4 + j * mlx->i.sl] = (mlx->obj.pixel[j][i]).g;
			mlx->i.data[2 + i * 4 + j * mlx->i.sl] = (mlx->obj.pixel[j][i]).r;
			++i;
		}
		++j;
	}
	return (0);
}
