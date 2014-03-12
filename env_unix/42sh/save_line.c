/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_line.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:30:45 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/05 14:05:10 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "sh.h"
#include "libft.h"

int				ft_putc(int c)
{
	ft_putchar_fd((char)c, 1);
	return (0);
}

static int		ft_short_mv(char *buf, t_sl **list, int *cursor_l, int co)
{
	int			len;

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
	else if (*cursor_l > 0 && KEY_ARROW_LEFT(buf))
		--(*cursor_l);
	else if (*cursor_l < len && KEY_ARROW_RIGHT(buf))
		++(*cursor_l);
	else
		return (1);
	return (0);
}

static int		ft_put_or_del_char(char *buf, t_sl **l, t_save *s, t_hl **hl)
{
	if (buf[0] >= ' ' && buf[0] <= '~' && buf[1] == 0)
	{
		if (ft_list_put_elem(buf[0], l, s->cursor_l) == -1)
			return (-1);
		++(s->cursor_l);
	}
	else if (s->cursor_l > 0 && KEY_DEL_LEFT(buf))
	{
		--(s->cursor_l);
		ft_list_del_elem(l, s->cursor_l);
	}
	else if (s->cursor_l < ft_slist_len(*l) && KEY_DEL_RIGHT(buf))
		ft_list_del_elem(l, s->cursor_l);
	else
		return (1);
	if (s->cursor_hl)
	{
		s->cursor_hl = 0;
		while ((*hl)->prev)
			*hl = (*hl)->prev;
	}
	return (0);
}

static int		ft_check_key(char *b, t_sl **l, t_save *s, t_hl **hl)
{
	int					do_it;
	struct winsize		w;
	int					old_line;

	do_it = 1;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	if ((s->co = w.ws_col) == 0)
	{
		s->cursor_l = -1;
		return (ft_error_msg("Put valid entry", ""));
	}
	old_line = (P_LEN + s->cursor_l) / s->co;
	if (KEY_ENTER(b))
	{
		s->cursor_l = -1;
		return (0);
	}
	if (((do_it = ft_put_or_del_char(b, l, s, hl)) == -1)
		|| (do_it && (do_it = ft_short_mv(b, l, &(s->cursor_l), s->co)) == -1)
		|| (do_it && (do_it = ft_fast_move(b, l, &(s->cursor_l))) == -1)
		|| (do_it && (do_it = ft_historic(b, l, s, hl)) == -1)
		|| (do_it && (do_it = ft_cut_copy_or_paste(b, l, s)) == -1))
		return (-1);
	ft_print(*l, s, old_line);
	return (0);
}

int				ft_save_line(t_hl **hlist, char **line, t_hl *move)
{
	char			buf[MAX_KEY_LEN + 1];
	t_save			save;
	t_sl			*list;

	list = NULL;
	save.copy = NULL;
	save.cursor_l = 0;
	save.cursor_hl = 0;
	ft_putstr("_$> ");
	while (save.cursor_l != -1)
	{
		ft_bzero(buf, MAX_KEY_LEN + 1);
		if (read(STDIN_FILENO, buf, MAX_KEY_LEN) == -1)
			return (-1);
		if (KEY_CTRL_D(buf))
			return (-2);
		if (ft_check_key(buf, &list, &save, &move))
			return (-1);
	}
	save.cursor_l = ft_slist_len(list);
	ft_print(list, &save, (P_LEN + save.cursor_l) / save.co);
	if ((ft_put_in_hist(hlist, list) == -1) || (ft_do_line(line, list)) == -1)
		return (-1);
	return (0);
}
