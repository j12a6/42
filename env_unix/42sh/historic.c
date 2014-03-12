/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:04:06 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:09:03 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

t_sl			*ft_listdup(t_sl *list)
{
	t_sl		*new;
	t_sl		*move;

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

static t_hl		*ft_hlist_new_elem(t_sl *list)
{
	t_hl		*new;

	if (!(new = (t_hl *)gmalloc(sizeof(*new))))
		return (NULL);
	new->hist = ft_listdup(list);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void		ft_move_hist(t_hl **hlist, t_save *save, t_sl **list, int flag)
{
	if ((*hlist)->next && flag == 1)
		*hlist = (*hlist)->next;
	else if ((*hlist)->prev && flag == -1)
		*hlist = (*hlist)->prev;
	*list = ft_listdup((*hlist)->hist);
	save->cursor_l = ft_slist_len(*list);
	save->cursor_hl += (flag == -1) ? -1 : 1;
}

int				ft_historic(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	if (KEY_ARROW_UP(buf) && *hlist)
	{
		if (save->cursor_hl && (*hlist)->next)
			ft_move_hist(hlist, save, list, 1);
		else if (save->cursor_hl == 0)
			ft_move_hist(hlist, save, list, 0);
	}
	else if (KEY_ARROW_DOWN(buf) && *hlist && save->cursor_hl > 0)
	{
		if (save->cursor_hl > 1)
			ft_move_hist(hlist, save, list, -1);
		else
		{
			*list = NULL;
			save->cursor_l = 0;
			save->cursor_hl = 0;
		}
	}
	else
		return (1);
	return (0);
}

int				ft_put_in_hist(t_hl **hlist, t_sl *list)
{
	t_hl	*new_elem;

	if (!list)
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
