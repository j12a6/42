/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 15:25:59 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/15 20:24:44 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_lstlen(t_ls *list)
{
	int		n;

	n = 0;
	while (list != NULL)
	{
		n++;
		list = list->next;
	}
	return (n);
}

static t_ls		*ft_max_list(t_ls *list, int r)
{
	t_ls	*max;
	max = list;

	while (list != NULL)
	{
		if (r * (ft_strcmp(list->name, max->name)) > 0)
			max = list;
		list = list->next;
	}
	return (max);
}

static void		ft_sort2(t_ls *list, t_ls *new_list, t_ls *save, int r)
{
	int		i;
	t_ls	*el1;
	t_ls	*max;

	el1 = list;
	max = ft_max_list(list, r);
	i = 1;
	while (i < ft_lstlen(el1))
	{
		save = max;
		while (list != NULL)
		{
			if (r * (ft_strcmp(list->name, save->name)) < 0
			&& r * (ft_strcmp(list->name, new_list->name)) > 0)
				save = list;
			list = list->next;
		}
		new_list->next = ft_ls_lstnew(save->name, save->time);
		new_list = new_list->next;
		list = el1;
		i++;
	}
}

t_ls			*ft_sort(t_ls *list, int r)
{
	t_ls	*el1;
	t_ls	*el2;
	t_ls	*new_list;
	t_ls	*save;

	el1 = list;
	save = list;
	while (list != NULL)
	{
		if (r * (ft_strcmp(list->name, save->name)) < 0)
			save = list;
		list = list->next;
	}
	new_list = ft_ls_lstnew(save->name, save->time);
	el2 = new_list;
	list = el1;
	ft_sort2(list, new_list, save, r);
	return (el2);
}
