/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_copy_or_paste.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:49:24 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:06 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

static int		ft_cut_or_copy_left(t_sl **list, t_save *save, int flag)
{
	int		i;
	t_sl	*move;

	i = -1;
	move = *list;
	if (save->copy)
	{
		gfree((void *)save->copy);
		save->copy = NULL;
	}
	while (++i < save->cursor_l)
	{
		if (ft_list_put_elem(move->c, &(save->copy), i))
			return (-1);
		move = move->next;
	}
	if (flag == 0)
	{
		*list = move;
		if (move)
			move->prev = NULL;
		save->cursor_l = 0;
	}
	return (0);
}

static int		ft_cut_or_copy_right(t_sl **list, t_save *save, int flag)
{
	t_sl	*move;
	int		i;

	move = *list;
	i = -1;
	while (++i < save->cursor_l)
		move = move->next;
	if (save->copy)
	{
		gfree((void *)save->copy);
		save->copy = NULL;
	}
	if (move && move->next)
	{
		move = move->next;
		save->copy = ft_listdup(move);
		if (flag == 0)
			move->prev->next = NULL;
	}
	return (0);
}

static int		ft_cut_or_copy_all(t_sl **list, t_save *save, int flag)
{
	if (save->copy)
	{
		gfree((void *)save->copy);
		save->copy = NULL;
	}
	save->copy = ft_listdup(*list);
	if (flag == 0)
	{
		*list = NULL;
		save->cursor_l = 0;
	}
	return (0);
}

static int		ft_paste(t_sl **list, t_save *save)
{
	t_sl	*move;

	move = save->copy;
	while (move)
	{
		if (ft_list_put_elem(move->c, list, save->cursor_l))
			return (-1);
		++(save->cursor_l);
		move = move->next;
	}
	return (0);
}

int				ft_cut_copy_or_paste(char *buf, t_sl **list, t_save *save)
{
	if (*list && KEY_CTRL_R(buf))
		ft_cut_or_copy_left(list, save, 0);
	else if (*list && KEY_CTRL_T(buf))
		ft_cut_or_copy_right(list, save, 0);
	else if (*list && KEY_CTRL_F(buf))
		ft_cut_or_copy_all(list, save, 0);
	else if (*list && KEY_CTRL_U(buf))
		ft_cut_or_copy_left(list, save, 1);
	else if (*list && KEY_CTRL_I(buf))
		ft_cut_or_copy_right(list, save, 1);
	else if (*list && KEY_CTRL_H(buf))
		ft_cut_or_copy_all(list, save, 1);
	else if (save->copy && KEY_CTRL_G(buf))
		ft_paste(list, save);
	else
		return (1);
	return (0);
}
