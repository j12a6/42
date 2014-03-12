/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:39:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:06:44 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_change_line(char *buf, t_sl **list, int *cursor_l, int co)
{
	int					len;

	len = ft_slist_len(*list);
	if (KEY_OPT_ARROW_UP(buf) && (P_LEN + *cursor_l) >= co)
	{
		*cursor_l -= co;
		if (*cursor_l < 0)
			*cursor_l = 0;
	}
	else if (KEY_OPT_ARROW_DOWN(buf)
			&& ((P_LEN + *cursor_l) / co) < ((P_LEN + len) / co))
	{
		if (len - *cursor_l > co)
			*cursor_l += co;
		else
			*cursor_l = len;
	}
	else
		return (1);
	return (0);
}
