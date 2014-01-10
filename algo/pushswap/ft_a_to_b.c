/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:05:14 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/10 10:19:08 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int		ft_a_before_send2(t_push *list, t_min *min)
{
	int		i;

	i = 0;
	while ((list->a)->nb != min->min)
	{
		list->a = ft_swap_rr(list->a);
		if (!list->b && ft_sort1(list->a) == 1)
		{
			ft_putstr("rra\n");
			return (1);
		}
		else
			ft_putstr("rra ");
	}
	return (0);
}

static int		ft_a_before_send(t_push *list, t_min *min)
{
	int		i;
	int		m;

	m = ft_count_elem(list->a);
	i = 0;
	if (min->ind_min <= m / 2)
	{
		while ((list->a)->nb != min->min)
		{
			list->a = ft_swap_r(list->a);
			if (!list->b && ft_sort1(list->a) == 1)
			{
				ft_putstr("ra\n");
				return (1);
			}
			else
				ft_putstr("ra ");
		}
	}
	else
	{
		if (ft_a_before_send2(list, min) == 1)
			return (1);
	}
	return (0);
}

static int		ft_put_all_b_in_a(t_push *list)
{
	while (list->b)
	{
		if ((list->b)->next)
		{
			list = ft_swap_pa(list);
			ft_putstr("pa ");
		}
		else
		{
			list = ft_swap_pa(list);
			ft_putstr("pa\n");
		}
	}
	return (1);
}

t_push			*ft_a_to_b(t_push *list, t_min *min)
{
	int		i;

	i = 0;
	while (list->a && (list->a)->next && i == 0)
	{
		ft_init_min_info(list->a, min);
		if ((i = ft_a_before_send(list, min)) == 1)
			return (list);
		else if (ft_sort1(list->a) == 1 && ft_sort2(list->b) == 1)
			i = ft_put_all_b_in_a(list);
		else
		{
			list = ft_swap_pb(list);
			ft_putstr("pb ");
		}
	}
	return (list);
}
