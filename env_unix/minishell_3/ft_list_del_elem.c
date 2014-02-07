/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 11:23:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 14:20:23 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_minishell3.h"
#include "libft.h"

static void		ft_list_del_elem_2(t_sl **sl, int cursor)
{
	t_sl		*tmp;
	t_sl		*move;
	int			i;

	move = *sl;
	if (cursor == 0)
		*sl = (*sl)->next;
	else
	{
		i = -1;
		while (++i < cursor - 1)
			move = move->next;
		tmp = move;
		move = move->next;
		tmp->next = move->next;
		if (move->next)
			(move->next)->prev = tmp;
	}
	(*sl)->prev = NULL;
	move->prev = NULL;
	move->next = NULL;
	gofree((void *)move);
}

void			ft_list_del_elem(t_sl **sl, int cursor)
{
	if (!(*sl)->next)
	{
		gofree((void *)*sl);
		*sl = NULL;
	}
	else
		ft_list_del_elem_2(sl, cursor);
}
