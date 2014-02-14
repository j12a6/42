/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 14:54:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/13 18:10:43 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"
#include "libft.h"

t_ll		*ft_create_light_elem(t_light light)
{
	t_ll	*new;

	if (!(new = (t_ll *)gmalloc(sizeof(*new))))
		return (NULL);
	new->light.c.x = light.c.x;
	new->light.c.y = light.c.y;
	new->light.c.z = light.c.z;
	new->light.r = light.r;
	new->next = NULL;
	return (new);
}

void		ft_fill_light_info(t_light *l, int fd)
{
	char	*line;
	char	**save;

	get_next_line(fd, &line);
	save = ft_strsplit(line, ',');
	ft_init_vect(&(l->c), ft_atod(save[0]), ft_atod(save[1]), ft_atod(save[2]));
	ft_free_char2(save);
	gfree((void *)line);
	get_next_line(fd, &line);
	l->r = ft_atoi(line);
	gfree((void *)line);
}

int			ft_save_light_in_list(t_ll **ll, int fd)
{
	t_light		light;
	t_ll		*new_elem;

	ft_fill_light_info(&light, fd);
	if (!(new_elem = ft_create_light_elem(light)))
		return (-1);
	if (*ll)
		new_elem->next = *ll;
	*ll = new_elem;
	return (0);
}
