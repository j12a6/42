/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:35:20 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/13 18:19:39 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_rtv1.h"
#include "libft.h"

int			ft_save_scene(t_obj *obj, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Open failed", 2);
		return (-1);
	}
	while (get_next_line(fd, &line) && ft_strcmp("#End", line) != 0)
	{
		if (ft_strcmp("#Light", line) == 0)
		{
			if (ft_save_light_in_list(&(obj->ll), fd) == -1)
				return (-1);
		}
		else if (ft_strcmp("#Sphere", line) == 0)
		{
			if (ft_save_sphere_in_list(&(obj->sl), fd) == -1)
				return (-1);
		}
		else if (ft_strcmp("#Plane", line) == 0)
		{
			if (ft_save_plane_in_list(&(obj->pl), fd) == -1)
				return (-1);
		}
		else if (ft_strcmp("", line) != 0)
		{
			ft_putendl_fd("File not valid", 2);
			return (-1);
		}
		gfree((void *)line);
	}
	return (0);
}
