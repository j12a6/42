/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 13:25:04 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/28 10:42:24 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_swap_s(t_lst *list)
{
	int		copy;

	if (!list || !list->next)
		return ;
	copy = list->nb;
	list->nb = (list->next)->nb;
	(list->next)->nb = copy;
}

t_push		*ft_swap_pa(t_push *list)
{
	t_lst	*tmp;

	if (!list->b)
		return (list);
	tmp = list->b;
	tmp = tmp->next;
	(list->b)->next = list->a;
	list->a = list->b;
	list->b = tmp;
	return (list);
}

t_push		*ft_swap_pb(t_push *list)
{
	t_lst	*tmp;

	if (!list->a)
		return (list);
	tmp = list->a;
	tmp = tmp->next;
	(list->a)->next = list->b;
	list->b = list->a;
	list->a = tmp;
	return (list);
}

t_lst		*ft_swap_r(t_lst *list)
{
	t_lst	*tmp;

	if (!list || !list->next)
		return (list);
	tmp = list;
	while (list->next)
		list = list->next;
	list->next = tmp;
	tmp = tmp->next;
	list->next->next = NULL;
	return (tmp);
}

t_lst		*ft_swap_rr(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	if (!list || !list->next)
		return (list);
	tmp = list;
	while (list->next->next)
		list = list->next;
	tmp2 = list;
	list = list->next;
	list->next = tmp;
	tmp2->next = NULL;
	return (list);
}
