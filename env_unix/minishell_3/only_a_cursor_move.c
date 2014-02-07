/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_a_cursor_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 10:54:59 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 12:07:37 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

static void		ft_go_to_prev_word(t_sl **sl, int *cursor)
{
	int		i;
	t_sl	*move;

	move = *sl;
	if (*cursor > 0)
		--(*cursor);
	i = -1;
	while (++i < *cursor)
		move = move->next;
	while (*cursor > 0 && move && move->prev
			&& !(move->c != ' ' && (move->prev)->c == ' '))
	{
		--(*cursor);
		move = move->prev;
	}
}

static void		ft_go_to_next_word(t_sl **sl, int *cursor)
{
	int		i;
	t_sl	*move;
	int		len;

	len = ft_slist_len(*sl);
	move = *sl;
	i = -1;
	while (++i < *cursor)
		move = move->next;
	while (*cursor < len && move && move->next
			&& !(move->c == ' ' && (move->next)->c != ' '))
	{
		move = move->next;
		++(*cursor);
	}
	if (*cursor < len)
		++(*cursor);
}

int				ft_fast_move(char *buf, t_sl **sl, int *cursor)
{
	if (*cursor > 0 && KEY_OPT_ARROW_LEFT(buf))
		ft_go_to_prev_word(sl, cursor);
	else if (*cursor < ft_slist_len(*sl) && KEY_OPT_ARROW_RIGHT(buf))
		ft_go_to_next_word(sl, cursor);
	else if (KEY_CTRL_A(buf))
		*cursor = 0;
	else if (KEY_CTRL_E(buf))
		*cursor = ft_slist_len(*sl);
	else
		return (1);
	return (0);
}

int				ft_little_move(char *buf, t_sl **sl, int *cursor, int co)
{
	int			len;

	len = ft_slist_len(*sl);
	if (KEY_OPT_ARROW_UP(buf) && (P_LEN + *cursor) >= co)
	{
		*cursor -= co;
		if (*cursor < 0)
			*cursor = 0;
	}
	else if (KEY_OPT_ARROW_DOWN(buf)
			&& ((P_LEN + *cursor) / co) < ((P_LEN + len) / co))
	{
		if (len - *cursor > co)
			*cursor += co;
		else
			*cursor = len;
	}
	else if (*cursor > 0 && KEY_ARROW_LEFT(buf))
		--(*cursor);
	else if (*cursor < len && KEY_ARROW_RIGHT(buf))
		++(*cursor);
	else
		return (1);
	return (0);
}
