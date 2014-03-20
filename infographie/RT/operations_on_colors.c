/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_on_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 09:52:40 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/20 17:09:32 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_init_color(t_c *color, int b, int g, int r)
{
	color->b = b;
	color->g = g;
	color->r = r;
}

void	ft_color_sum(t_c *color, t_c color1, t_c color2)
{
	color->b = color1.b + color2.b;
	color->g = color1.g + color2.g;
	color->r = color1.r + color2.r;
}

void	ft_mult_color_by_color(t_c *color, t_c color1, t_c color2)
{
	color->b = color1.b * color2.b;
	color->g = color1.g * color2.g;
	color->r = color1.r * color2.r;
}

void	ft_mult_color_by_nb(t_c *color, t_c c1, double scalar)
{
	color->b = c1.b * scalar;
	color->g = c1.g * scalar;
	color->r = c1.r * scalar;
}
