/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:54:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/13 18:55:18 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "libft.h"

#include <stdio.h>
t_sl		*ft_create_sphere_elem(t_sph sph)
{
	t_sl	*new;

	if (!(new = (t_sl *)gmalloc(sizeof(*new))))
		return (NULL);
	new->sph.c.x = sph.c.x;
	new->sph.c.y = sph.c.y;
	new->sph.c.z = sph.c.z;
	new->sph.r = sph.r;
	new->sph.ind = sph.ind;
	new->sph.clr.b = sph.clr.b;
	new->sph.clr.g = sph.clr.g;
	new->sph.clr.r = sph.clr.r;
	new->next = NULL;
	return (new);
}

void		ft_fill_sphere_info(t_sph *s, int fd)
{
	char	*line;
	char	**save;

	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(s->c), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_free_char2(save);
	gfree((void *)line);
	get_next_line(fd, &line);
	s->r = ft_atoi(line);
	gfree((void *)line);
	get_next_line(fd, &line);
	s->ind = ft_atoi(line);
	gfree((void *)line);
	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	s->clr.b = ft_atoi(save[0]);
	s->clr.g = ft_atoi(save[1]);
	s->clr.r = ft_atoi(save[2]);
	ft_free_char2(save);
	gfree((void *)line);
}

int			ft_save_sphere_in_list(t_sl **sl, int fd)
{
	t_sph		sph;
	t_sl		*new_elem;

	ft_fill_sphere_info(&sph, fd);
	if (!(new_elem = ft_create_sphere_elem(sph)))
		return (-1);
	if (*sl)
		new_elem->next = *sl;
	*sl = new_elem;
	return (0);
}
