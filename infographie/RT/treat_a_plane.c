/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 17:41:40 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 09:58:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>
#include "libft.h"
int		ft_treat_a_plane(void *data, t_c *color)
{
	t_pla	*pla;

	pla = (t_pla *)data;
	*color = pla->sf;
	return (0);
}
