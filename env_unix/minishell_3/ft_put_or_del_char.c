/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_or_del_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 12:51:44 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 12:54:25 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"

int		ft_put_or_del_char(char *buf, t_sl **sl, t_save *save, t_hl **hl)
{
	if (buf[0] >= ' ' && buf[0] <= '~' && buf[1] == 0)
	{
		if (ft_list_put_elem(buf[0], sl, save->cursor) == -1)
			return (-1);
		++(save->cursor);
	}
	else if (save->cursor > 0 && KEY_DEL_LEFT(buf))
	{
		--(save->cursor);
		ft_list_del_elem(sl, save->cursor);
	}
	else if (save->cursor < ft_slist_len(*sl) && KEY_DEL_RIGHT(buf))
		ft_list_del_elem(sl, save->cursor);
	else
		return (1);
	if (save->hist_nb)
	{
		save->hist_nb = 0;
		while ((*hl)->prev)
			*hl = (*hl)->prev;
	}
	return (0);
}
