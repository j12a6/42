/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_put_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 15:06:03 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:32 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

t_sl			*ft_list_new_elem(char c)
{
	t_sl	*list;

	if (!(list = (t_sl *)gmalloc(sizeof(t_sl))))
		return (NULL);
	list->c = c;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

static int		ft_list_put_elem_2(char c, t_sl **list, int cursor_l)
{
	int		i;
	t_sl	*move;
	t_sl	*new_elem;
	t_sl	*tmp;

	if (!(new_elem = ft_list_new_elem(c)))
		return (-1);
	move = *list;
	if (cursor_l == 0)
	{
		(*list)->prev = new_elem;
		new_elem->next = *list;
		*list = new_elem;
		return (0);
	}
	i = -1;
	while (++i < cursor_l - 1)
		move = move->next;
	tmp = move;
	move = move->next;
	tmp->next = new_elem;
	new_elem->prev = tmp;
	new_elem->next = move;
	move->prev = new_elem;
	return (0);
}

int				ft_list_put_elem(char c, t_sl **list, int cursor_l)
{
	t_sl	*move;
	t_sl	*new_elem;

	if (!*list)
	{
		if (!(*list = ft_list_new_elem(c)))
			return (-1);
	}
	else if (cursor_l == ft_slist_len(*list))
	{
		move = *list;
		while (move->next)
			move = move->next;
		if (!(new_elem = ft_list_new_elem(c)))
			return (-1);
		new_elem->prev = move;
		move->next = new_elem;
	}
	else
	{
		if (ft_list_put_elem_2(c, list, cursor_l) == -1)
			return (-1);
	}
	return (0);
}
