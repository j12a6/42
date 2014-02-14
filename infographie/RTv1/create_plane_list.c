/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:54:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/13 18:48:17 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "libft.h"

t_pl		*ft_create_plane_elem(t_plan plan)
{
	t_pl	*new;

	if (!(new = (t_pl *)gmalloc(sizeof(*new))))
		return (NULL);
	new->plan.p.x = plan.p.x;
	new->plan.p.y = plan.p.y;
	new->plan.p.z = plan.p.z;
	new->plan.n.x = plan.n.x;
	new->plan.n.y = plan.n.y;
	new->plan.n.z = plan.n.z;
	new->plan.ind = plan.ind;
	new->plan.clr.b = plan.clr.b;
	new->plan.clr.g = plan.clr.g;
	new->plan.clr.r = plan.clr.r;
	new->next = NULL;
	return (new);
}

void		ft_fill_plane_info(t_plan *p, int fd)
{
	char	*line;
	char	**save;

	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(p->p), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_free_char2(save);
	gfree((void *)line);
	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(p->n), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_free_char2(save);
	gfree((void *)line);
	get_next_line(fd, &line);
	p->ind = ft_atod(line);
	gfree((void *)line);
	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	p->clr.b = ft_atoi(save[0]);
	p->clr.g = ft_atoi(save[1]);
	p->clr.r = ft_atoi(save[2]);
	gfree((void *)line);
	ft_free_char2(save);
}

int			ft_save_plane_in_list(t_pl **pl, int fd)
{
	t_plan	plan;
	t_pl	*new_elem;

	ft_fill_plane_info(&plan, fd);
	if (!(new_elem = ft_create_plane_elem(plan)))
		return (-1);
	if (*pl)
		new_elem->next = *pl;
	*pl = new_elem;
	return (0);
}
