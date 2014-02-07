/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:04:06 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 18:21:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_minishell3.h"
#include "libft.h"

t_sl			*ft_listdup(t_sl *sl)
{
	t_sl	*new;
	t_sl	*move;

	if (!(new = ft_list_new_elem(sl->c)))
		return (NULL);
	move = new;
	sl = sl->next;
	while (sl)
	{
		if (!(move->next = ft_list_new_elem(sl->c)))
			return (NULL);
		move->next->prev = move;
		move = move->next;
		sl = sl->next;
	}
	return (new);
}

static t_hl		*ft_hl_new_elem(t_sl *sl)
{
	t_hl	*new;
	t_sl	*tmp;
	t_sl	*move;

	if (!(new = (t_hl *)gmalloc(sizeof(*new))))
		return (NULL);
	if (!(new->hist = ft_list_new_elem(sl->c)))
		return (NULL);
	move = new->hist;
	tmp = sl;
	sl = sl->next;
	gofree((void *)tmp);
	while (sl)
	{
		if (!(move->next = ft_list_new_elem(sl->c)))
			return (NULL);
		move = move->next;
		tmp = sl;
		sl = sl->next;
		gofree((void *)tmp);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int				ft_update_history(t_hl **hl, t_sl *sl)
{
	t_hl	*new_elem;
	t_sl	*move;

	if (!sl)
		return (0);
	move = ft_listdup(sl);
	if (!(new_elem = ft_hl_new_elem(move)))
		return (-1);
	if (!*hl)
		*hl = new_elem;
	else
	{
		new_elem->next = *hl;
		(*hl)->prev = new_elem;
		*hl = new_elem;
	}
	return (0);
}
