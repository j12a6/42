/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_up_or_down.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:39:51 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 12:00:08 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"

int		ft_change_line(char *buf, t_sl **sl, int *cursor, int co)
{
	int					len;

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
	else
		return (1);
	return (0);
}
