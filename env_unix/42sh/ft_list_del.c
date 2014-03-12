/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 21:49:17 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:25 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

static void		ft_list_del_elem_2(t_sl **list, int cursor_l)
{
	t_sl		*tmp;
	t_sl		*move;
	int			i;

	move = *list;
	if (cursor_l == 0)
		*list = (*list)->next;
	else
	{
		i = -1;
		while (++i < cursor_l - 1)
			move = move->next;
		tmp = move;
		move = move->next;
		tmp->next = move->next;
		if (move->next)
			(move->next)->prev = tmp;
	}
	(*list)->prev = NULL;
	move->prev = NULL;
	move->next = NULL;
	gfree((void *)move);
}

void			ft_list_del_elem(t_sl **list, int cursor_l)
{
	if (!(*list)->next)
	{
		gfree((void *)*list);
		*list = NULL;
	}
	else
		ft_list_del_elem_2(list, cursor_l);
}
