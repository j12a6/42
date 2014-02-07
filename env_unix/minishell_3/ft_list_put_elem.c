/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_put_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:06:03 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 12:00:00 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

t_sl			*ft_list_new_elem(char c)
{
	t_sl	*sl;

	if (!(sl = (t_sl *)gmalloc(sizeof(t_sl))))
		return (NULL);
	sl->c = c;
	sl->next = NULL;
	sl->prev = NULL;
	return (sl);
}

static int		ft_list_put_elem_2(char c, t_sl **sl, int cursor)
{
	int		i;
	t_sl	*move;
	t_sl	*new_elem;
	t_sl	*tmp;

	if (!(new_elem = ft_list_new_elem(c)))
		return (-1);
	move = *sl;
	if (cursor == 0)
	{
		(*sl)->prev = new_elem;
		new_elem->next = *sl;
		*sl = new_elem;
	}
	else
	{
		i = -1;
		while (++i < cursor - 1)
			move = move->next;
		tmp = move;
		move = move->next;
		tmp->next = new_elem;
		new_elem->prev = tmp;
		new_elem->next = move;
		move->prev = new_elem;
	}
	return (0);
}

int				ft_list_put_elem(char c, t_sl **sl, int cursor)
{
	t_sl	*move;
	t_sl	*new_elem;

	if (!*sl)
	{
		if (!(*sl = ft_list_new_elem(c)))
			return (-1);
	}
	else if (cursor == ft_slist_len(*sl))
	{
		move = *sl;
		while (move->next)
			move = move->next;
		if (!(new_elem = ft_list_new_elem(c)))
			return (-1);
		new_elem->prev = move;
		move->next = new_elem;
	}
	else
	{
		if (ft_list_put_elem_2(c, sl, cursor) == -1)
			return (-1);
	}
	return (0);
}
