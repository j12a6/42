/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:35:20 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 18:15:17 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_rtv1.h"
#include "libft.h"

static int	ft_save_scene2(t_cam cam, t_obj *obj, char *line, int fd)
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
	else if (ft_strcmp("#Cylinder", line) == 0)
	{
		if (ft_save_cylinder_in_list(cam, &(obj->cyll), fd) == -1)
			return (-1);
	}
	return (0);
}

int			ft_save_scene(t_obj *obj, char *file)
{
	int		fd;
	char	*line;
	t_cam	cam;

	ft_init_vect(&cam.e, CAM_X, CAM_Y, CAM_Z);
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putendl_fd("Open failed", 2);
		return (-1);
	}
	while (get_next_line(fd, &line) && ft_strcmp("#End", line) != 0)
	{
		if (ft_save_scene2(cam, obj, line, fd) == -1)
			return (-1);
		gofree((void *)line);
	}
	return (0);
}
