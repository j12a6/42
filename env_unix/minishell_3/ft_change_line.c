/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 15:39:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/05 14:20:13 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <term.h>
#include <string.h>
#include <unistd.h>
#include "ft_minishell3.h"

int		ft_change_line(char *buf, t_sl **list, int *cursor, int co)
{
	int					len;

	len = ft_slist_len(*list);
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
