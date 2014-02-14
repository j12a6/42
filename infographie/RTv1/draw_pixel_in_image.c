/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_in_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 19:41:50 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/13 18:14:15 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_rtv1.h"

void	ft_put_sphere_pixel(t_mlx *mlx, int i, int j, t_sol sol)
{
	t_sl	*move;
	int		k;

	move = mlx->obj.sl;
	k = -1;
	while (++k < sol.ind)
		move = move->next;
	mlx->i.data[i * 4 + 0 + j * mlx->i.sl] = move->sph.clr.b;
	mlx->i.data[i * 4 + 1 + j * mlx->i.sl] = move->sph.clr.g;
	mlx->i.data[i * 4 + 2 + j * mlx->i.sl] = move->sph.clr.r;
}

void	ft_put_plane_pixel(t_mlx *mlx, int i, int j, t_sol sol)
{
	t_pl	*move;
	int		k;

	move = mlx->obj.pl;
	k = -1;
	while (++k < sol.ind)
		move = move->next;
	mlx->i.data[i * 4 + 0 + j * mlx->i.sl] = move->plan.clr.b;
	mlx->i.data[i * 4 + 1 + j * mlx->i.sl] = move->plan.clr.g;
	mlx->i.data[i * 4 + 2 + j * mlx->i.sl] = move->plan.clr.r;
}

void	ft_put_pixel_in_image(t_mlx *mlx, int i, int j, t_sol sol)
{
	if (sol.c == 's')
		ft_put_sphere_pixel(mlx, i, j, sol);
	else if (sol.c == 'p')
		ft_put_plane_pixel(mlx, i, j, sol);
}
