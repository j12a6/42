/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 15:25:59 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/15 20:32:11 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls		*ft_min_list_t(t_ls *list, int r)
{
	t_ls	*old;
	old = list;

	while (list != NULL)
	{
		if (r * (list->time - old->time) < 0
		|| (list->time == old->time && ft_strcmp(list->name, old->name) > 0))
			old = list;
		list = list->next;
	}
	return (old);
}

static void		ft_sort_t_2(t_ls *list, t_ls *new_list, t_ls *save, int r)
{
	int		i;
	t_ls	*el1;
	t_ls	*old;

	el1 = list;
	old = ft_min_list_t(list, r);
	i = 1;
	while (i < ft_lstlen(el1))
	{
		save = old;
		while (list != NULL)
		{
			if ((r * (list->time - save->time) > 0 || (list->time == save->time
			&& ft_strcmp(list->name, save->name) < 0))
			&& (r * (list->time - new_list->time) < 0
			|| (list->time == new_list->time
			&& ft_strcmp(list->name, new_list->name) > 0)))
				save = list;
			list = list->next;
		}
		new_list->next = ft_ls_lstnew(save->name, save->time);
		new_list = new_list->next;
		list = el1;
		i++;
	}
}

t_ls			*ft_sort_t(t_ls *list, int r)
{
	t_ls	*el1;
	t_ls	*el2;
	t_ls	*new_list;
	t_ls	*save;

	el1 = list;
	save = list;
	while (list != NULL)
	{
		if (r * (list->time - save->time) > 0
		|| (list->time == save->time && ft_strcmp(list->name, save->name) < 0))
			save = list;
		list = list->next;
	}
	new_list = ft_ls_lstnew(save->name, save->time);
	el2 = new_list;
	list = el1;
	ft_sort_t_2(list, new_list, save, r);
	return (el2);
}
