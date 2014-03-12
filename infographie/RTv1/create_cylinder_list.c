/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:54:32 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 18:17:29 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "libft.h"

static void		ft_color(t_clr *color, int b, int g, int r)
{
	(*color).b = b;
	(*color).g = g;
	(*color).r = r;
}

t_cyll			*ft_create_cylinder_elem(t_cam cam, t_cyl cyl)
{
	t_cyll	*new;
	int		i;

	if (!(new = (t_cyll *)gmalloc(sizeof(*new))))
		return (NULL);
	ft_init_vect(&(new->cyl.c), cyl.c.x, cyl.c.y, cyl.c.z);
	ft_init_vect(&(new->cyl.a), cyl.a.x, cyl.a.y, cyl.a.z);
	new->cyl.r = cyl.r;
	new->cyl.ind = cyl.ind;
	ft_color(&(new->cyl.clr), cyl.clr.b, cyl.clr.g, cyl.clr.r);
	if (!(new->cyl.mat = (double **)gmalloc(sizeof(double *) * 3)))
		return (NULL);
	i = -1;
	while (++i < 3)
	{
		if (!(new->cyl.mat[i] = (double *)gmalloc(sizeof(double) * 1)))
			return (NULL);
	}
	ft_save_transfer_matrix_inverse(&(new->cyl.mat), &(new->cyl.b), cyl.a);
	new->cyl.c2 = ft_transform_in_new_basis(new->cyl.c, new->cyl.mat);
	new->cyl.e2 = ft_transform_in_new_basis(cam.e, new->cyl.mat);
	new->cyl.ce = ft_diff_vect(new->cyl.e2, new->cyl.c2);
	new->next = NULL;
	return (new);
}

void			ft_fill_cylinder_info(t_cyl *c, int fd)
{
	char	*line;
	char	**save;

	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(c->c), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_ts_free(save);
	gofree((void *)line);
	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(c->a), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_ts_free(save);
	gofree((void *)line);
	get_next_line(fd, &line);
	c->r = ft_atoi(line);
	gofree((void *)line);
	get_next_line(fd, &line);
	c->ind = ft_atoi(line);
	gofree((void *)line);
	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_color(&(c->clr), ft_atoi(save[0]), ft_atoi(save[1]), ft_atoi(save[2]));
	ft_ts_free(save);
	gofree((void *)line);
}

int				ft_save_cylinder_in_list(t_cam cam, t_cyll **cyll, int fd)
{
	t_cyl		cyl;
	t_cyll		*new_elem;

	ft_fill_cylinder_info(&cyl, fd);
	if (!(new_elem = ft_create_cylinder_elem(cam, cyl)))
		return (-1);
	if (*cyll)
		new_elem->next = *cyll;
	*cyll = new_elem;
	return (0);
}
