/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_copy_or_paste.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:49:24 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 14:19:36 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

static int		ft_cut_or_copy_left(t_sl **sl, t_save *save, int flag)
{
	int		i;
	t_sl	*move;

	move = *sl;
	if (save->copy)
	{
		gofree((void *)save->copy);
		save->copy = NULL;
	}
	i = -1;
	while (++i < save->cursor)
	{
		if (ft_list_put_elem(move->c, &(save->copy), i))
			return (-1);
		move = move->next;
	}
	if (flag == 0)
	{
		*sl = move;
		if (move)
			move->prev = NULL;
		save->cursor = 0;
	}
	return (0);
}

static int		ft_cut_or_copy_right(t_sl **sl, t_save *save, int flag)
{
	int		i;
	t_sl	*move;

	move = *sl;
	if (save->copy)
	{
		gofree((void *)save->copy);
		save->copy = NULL;
	}
	i = -1;
	while (++i < save->cursor)
		move = move->next;
	if (move && move->next)
	{
		move = move->next;
		save->copy = ft_listdup(move);
		if (flag == 0)
			move->prev->next = NULL;
	}
	return (0);
}

static int		ft_cut_or_copy_all(t_sl **sl, t_save *save, int flag)
{
	if (save->copy)
	{
		gofree((void *)save->copy);
		save->copy = NULL;
	}
	save->copy = ft_listdup(*sl);
	if (flag == 0)
	{
		*sl = NULL;
		save->cursor = 0;
	}
	return (0);
}

static int		ft_paste(t_sl **sl, t_save *save)
{
	t_sl	*move;

	move = save->copy;
	while (move)
	{
		if (ft_list_put_elem(move->c, sl, save->cursor))
			return (-1);
		++(save->cursor);
		move = move->next;
	}
	return (0);
}

int				ft_cut_copy_or_paste(char *buf, t_sl **sl, t_save *save)
{
	if (*sl && KEY_CTRL_R(buf))
		ft_cut_or_copy_left(sl, save, 0);
	else if (*sl && KEY_CTRL_T(buf))
		ft_cut_or_copy_right(sl, save, 0);
	else if (*sl && KEY_CTRL_F(buf))
		ft_cut_or_copy_all(sl, save, 0);
	else if (*sl && KEY_CTRL_U(buf))
		ft_cut_or_copy_left(sl, save, 1);
	else if (*sl && KEY_CTRL_I(buf))
		ft_cut_or_copy_right(sl, save, 1);
	else if (*sl && KEY_CTRL_H(buf))
		ft_cut_or_copy_all(sl, save, 1);
	else if (save->copy && KEY_CTRL_G(buf))
		ft_paste(sl, save);
	else
		return (1);
	return (0);
}
