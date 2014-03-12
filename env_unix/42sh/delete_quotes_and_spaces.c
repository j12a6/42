/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_quotes_and_spaces.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:45:34 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

static void		ft_delete_plist_last_elem(t_p **p, t_p **move)
{
	if ((*move)->prev)
		(*move)->prev->next = NULL;
	if (*move == *p)
	{
		gfree((void *)(*move)->tok);
		gfree((void *)(*move));
		*p = NULL;
	}
	else
	{
		gfree((void *)(*move)->tok);
		gfree((void *)(*move));
	}
	*move = NULL;
}

static void		ft_delete_plist_elem(t_p **p, t_p **move)
{
	t_p		*tmp;

	tmp = *move;
	if (*move && (*move)->next)
	{
		*move = (*move)->next;
		if (*p == (*move)->prev)
			*p = (*p)->next;
		if (tmp->prev)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		else
			tmp->next->prev = NULL;
		gfree((void *)tmp->tok);
		gfree((void *)tmp);
	}
	else
		ft_delete_plist_last_elem(p, move);
}

static void		ft_is_empty_string(t_p **p, t_p **move)
{
	ft_delete_plist_elem(p, move);
	(*move)->tok[0] = '\0';
	(*move)->type = WORD;
}

int				ft_delete_quotes_and_spaces(t_p **p, int ind)
{
	t_p		*m;

	m = *p;
	if (ind)
	{
		ft_putstr_fd("Unmatched ", 2);
		if (ind == 1)
			ft_putendl_fd("\'.", 2);
		else
			ft_putendl_fd("\".", 2);
		return (-1);
	}
	while (m)
	{
		if (m->type == SPACE
			|| (m->type == QUO_S && (!m->next || m->next->type != QUO_S))
			|| (m->type == QUO_D && (!m->next || m->next->type != QUO_D)))
			ft_delete_plist_elem(p, &m);
		else if (m->type == QUO_S || m->type == QUO_D)
			ft_is_empty_string(p, &m);
		else
			m = m->next;
	}
	return (0);
}
