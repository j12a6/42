/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 15:54:01 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/04 11:44:33 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_minishell3.h"

t_sl			*ft_listdup(t_sl *list)
{
	t_sl	*new;
	t_sl	*move;

	if (!(new = ft_list_new_elem(list->c)))
		return (NULL);
	move = new;
	list = list->next;
	while (list)
	{
		if (!(move->next = ft_list_new_elem(list->c)))
			return (NULL);
		move->next->prev = move;
		move = move->next;
		list = list->next;
	}
	return (new);
}

static t_hl		*ft_hlist_new_elem(t_sl **list)
{
	t_hl	*new;
	t_sl	*tmp;
	t_sl	*move;

	if (!(new = (t_hl *)malloc(sizeof(*new))))
		return (NULL);
	if (!(new->hist = ft_list_new_elem((*list)->c)))
		return (NULL);
	move = new->hist;
	tmp = *list;
	*list = (*list)->next;
	free((void *)tmp);
	while (*list)
	{
		if (!(move->next = ft_list_new_elem((*list)->c)))
			return (NULL);
		move = move->next;
		tmp = *list;
		*list = (*list)->next;
		free((void *)tmp);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int			ft_in_history(t_hl **hlist, t_sl **list)
{
	t_hl	*new_elem;

	if (!*list)
		return (0);
	if (!(new_elem = ft_hlist_new_elem(list)))
		return (-1);
	if (!*hlist)
		*hlist = new_elem;
	else
	{
		new_elem->next = *hlist;
		(*hlist)->prev = new_elem;
		*hlist = new_elem;
	}
	return (0);
}
