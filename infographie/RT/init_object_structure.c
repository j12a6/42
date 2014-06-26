/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_structure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 16:26:25 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/27 23:14:17 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"

void	ft_init_ptr_fct_intersect(t_obj *obj)
{
	obj->intersect[0] = ft_intersect_a_box;
	obj->intersect[1] = ft_intersect_a_sphere;
	obj->intersect[2] = ft_intersect_a_plane;
	obj->intersect[3] = ft_intersect_a_disk;
	obj->intersect[4] = ft_intersect_a_cylinder;
	obj->intersect[5] = ft_intersect_a_cone;
	obj->treatment[0] = ft_treat_a_box;
	obj->treatment[1] = ft_treat_a_sphere;
	obj->treatment[2] = ft_treat_a_plane;
	obj->treatment[3] = ft_treat_a_disk;
	obj->treatment[4] = ft_treat_a_cylinder;
	obj->treatment[5] = ft_treat_a_cone;
}

int		ft_init_object_structure(t_obj *obj)
{
	int		i;

	if (!(obj->pixel = (t_c **)gmalloc(sizeof(t_c *) * HEIGHT))
		|| !(obj->type = (void ***)gmalloc(sizeof(void **) * NB_TYPE))
		|| !(obj->nb = (int *)gmalloc(sizeof(int) * NB_TYPE)))
		return (-1);
	i = -1;
	while (++i < HEIGHT)
	{
		if (!(obj->pixel[i] = (t_c *)gmalloc(sizeof(t_c) * WIDTH)))
			return (-1);
	}
	i = -1;
	while (++i < NB_TYPE)
		obj->nb[i] = 0;
	ft_init_ptr_fct_intersect(obj);
	ft_init_color(&(obj->bg_clr), 0, 0, 0);
	return (0);
}

int		ft_do_scene(t_obj *obj, char *map)
{
	if ((map[0] != '1' && map[0] != '2') || map[1])
		return (-1);
	if (map[0] == '1')
		return (ft_scene1(obj));
	else
		return (ft_scene2(obj));
}
