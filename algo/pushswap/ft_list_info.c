/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:05:14 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/27 14:37:19 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_lst	*ft_last(t_lst *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int		ft_count_elem(t_lst *list)
{
	int		n;

	n = 0;
	while (list)
	{
		n++;
		list = list->next;
	}
	return (n);
}

int		ft_sort1(t_lst *list)
{
	while (list && list->next)
	{
		if (list->nb > (list->next)->nb)
			return (-1);
		list = list->next;
	}
	return (1);
}

int		ft_sort2(t_lst *list)
{
	while (list && list->next)
	{
		if (list->nb < (list->next)->nb)
			return (-1);
		list = list->next;
	}
	return (1);
}

void	ft_init_min_info(t_lst *list, t_min *min)
{
	int		i;
	int		k;
	t_lst	*first;

	first = list;
	min->min = list->nb;
	min->ind_min = 0;
	while (list)
	{
		if (list->nb < min->min)
			min->min = list->nb;
		list = list->next;
	}
	list = first;
	i = 0;
	k = 0;
	while (list)
	{
		if (list->nb == min->min)
			i = k;
		k++;
		list = list->next;
	}
	min->ind_min = i;
}
