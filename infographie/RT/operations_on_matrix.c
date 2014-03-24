/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_on_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 16:57:14 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/24 12:30:54 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

int		ft_matrix_alloc(double ***mat)
{
	int		i;

	if (!(*mat = (double **)gmalloc(sizeof(double *) * 4)))
		return (-1);
	i = -1;
	while (++i < 4)
	{
		if (!((*mat)[i] = (double *)gmalloc(sizeof(double) * 4)))
			return (-1);
	}
	return (0);
}

double	**ft_init_matrix(t_v *v1, t_v *v2, t_v *v3, t_v *trans)
{
	double	**mat;

	mat = NULL;
	if (ft_matrix_alloc(&mat) == -1)
		return (NULL);
	mat[0][0] = v1->x;
	mat[1][0] = v1->y;
	mat[2][0] = v1->z;
	mat[3][0] = 0;
	mat[0][1] = v2->x;
	mat[1][1] = v2->y;
	mat[2][1] = v2->z;
	mat[3][1] = 0;
	mat[0][2] = v3->x;
	mat[1][2] = v3->y;
	mat[2][2] = v3->z;
	mat[3][2] = 0;
	mat[0][3] = trans->x;
	mat[1][3] = trans->y;
	mat[2][3] = trans->z;
	mat[3][3] = 1;
	return (mat);
}

void	ft_mult_vect_by_matrix(t_v *v, double **mat, t_v v1)
{
	double	homo;

	v->x = v1.x * mat[0][0] + v1.y * mat[1][0] + v1.z * mat[2][0] + mat[3][0];
	v->y = v1.x * mat[0][1] + v1.y * mat[1][1] + v1.z * mat[2][1] + mat[3][1];
	v->z = v1.x * mat[0][2] + v1.y * mat[1][2] + v1.z * mat[2][2] + mat[3][2];
	homo = v1.x * mat[0][3] + v1.y * mat[1][3] + v1.z * mat[2][3] + mat[3][3];
	if (homo != 1 && homo != 0)
	{
		v->x /= homo;
		v->y /= homo;
		v->z /= homo;
	}
}
