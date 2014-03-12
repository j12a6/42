/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_cursor_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 10:54:59 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:38 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		ft_go_to_prev_word(t_sl **list, int *cursor_l)
{
	int		i;
	t_sl	*move;

	move = *list;
	if (*cursor_l > 0)
		--(*cursor_l);
	i = -1;
	while (++i < *cursor_l)
		move = move->next;
	while (*cursor_l > 0 && move && move->prev
			&& !(move->c != ' ' && (move->prev)->c == ' '))
	{
		--(*cursor_l);
		move = move->prev;
	}
}

static void		ft_go_to_next_word(t_sl **list, int *cursor_l)
{
	int		i;
	t_sl	*move;
	int		len;

	len = ft_slist_len(*list);
	move = *list;
	i = -1;
	while (++i < *cursor_l)
		move = move->next;
	while (*cursor_l < len && move && move->next
			&& !(move->c == ' ' && (move->next)->c != ' '))
	{
		move = move->next;
		++(*cursor_l);
	}
	if (*cursor_l < len)
		++(*cursor_l);
}

int				ft_fast_move(char *buf, t_sl **list, int *cursor_l)
{
	if (*cursor_l > 0 && KEY_OPT_ARROW_LEFT(buf))
		ft_go_to_prev_word(list, cursor_l);
	else if (*cursor_l < ft_slist_len(*list) && KEY_OPT_ARROW_RIGHT(buf))
		ft_go_to_next_word(list, cursor_l);
	else if (KEY_CTRL_A(buf))
		*cursor_l = 0;
	else if (KEY_CTRL_E(buf))
		*cursor_l = ft_slist_len(*list);
	else
		return (1);
	return (0);
}
