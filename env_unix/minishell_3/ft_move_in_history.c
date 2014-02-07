/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_in_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 12:31:04 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 18:21:13 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_minishell3.h"

static void		ft_move_hist(t_hl **hl, t_save *save, t_sl **sl, int flag)
{
	if ((*hl)->next && flag == 1)
		*hl = (*hl)->next;
	else if ((*hl)->prev && flag == -1)
		*hl = (*hl)->prev;
	*sl = ft_listdup((*hl)->hist);
	save->cursor = ft_slist_len(*sl);
	if (flag == 0 || flag == 1)
		++(save->hist_nb);
	else if (flag == -1)
		--(save->hist_nb);
}

int				ft_move_in_history(char *buf, t_sl **sl, t_save *save, t_hl **move)
{
	if (KEY_ARROW_UP(buf) && *move)
	{
		if (save->hist_nb == 0)
			ft_move_hist(move, save, sl, 0);
		else if ((*move)->next)
			ft_move_hist(move, save, sl, 1);
	}
	else if (KEY_ARROW_DOWN(buf) && *move)
	{
		if ((*move)->prev)
			ft_move_hist(move, save, sl, -1);
		else
		{
			*sl = NULL;
			save->cursor = 0;
		}
	}
	else
		return (1);
	return (0);
}
