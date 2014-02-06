/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_final_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:30:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/06 13:07:09 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include "ft_minishell3.h"
#include "libft.h"

static int		ft_little_move(char *buf, t_sl **list, int *cursor, int co)
{
	int			len;

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
	else if (*cursor > 0 && KEY_ARROW_LEFT(buf))
		--(*cursor);
	else if (*cursor < len && KEY_ARROW_RIGHT(buf))
		++(*cursor);
	else
		return (1);
	return (0);
}

static int		ft_put_or_del_char(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	if (buf[0] >= ' ' && buf[0] <= '~' && buf[1] == 0)
	{
		if (ft_list_put_elem(buf[0], list, save->cursor) == -1)
			return (-1);
		++(save->cursor);
	}
	else if (save->cursor > 0 && KEY_DEL_LEFT(buf))
	{
		--(save->cursor);
		ft_list_del_elem(list, save->cursor);
	}
	else if (save->cursor < ft_slist_len(*list) && KEY_DEL_RIGHT(buf))
		ft_list_del_elem(list, save->cursor);
	else
		return (1);
	if (save->hist_nb)
	{
		save->hist_nb = 0;
		while ((*hlist)->prev)
			*hlist = (*hlist)->prev;
	}
	return (0);
}

static int 		ft_check(char *buf, t_sl **list, t_save *save, t_hl **hlist)
{
	int					do_it;
	struct winsize		w;
	int					old_line;

	do_it = 1;
	if (KEY_ENTER(buf))
	{
		do_it = 0;
		save->cursor = -1;
		return (0);
	}
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	save->co = w.ws_col;
	old_line = (P_LEN + save->cursor) / save->co;
	if (do_it && (do_it = ft_put_or_del_char(buf, list, save, hlist)) == -1)
		return (-1);
	if (do_it && (do_it = ft_little_move(buf, list, &(save->cursor), save->co)) == -1)
		return (-1);
	if (do_it && (do_it = ft_fast_move(buf, list, &(save->cursor), save->co)) == -1)
		return (-1);
	if (do_it && (do_it = ft_historic(buf, list, save, hlist)) == -1)
		return (-1);
	if (do_it && (do_it = ft_cut_copy_or_paste(buf, list, save)) == -1)
		return (-1);
	ft_print(*list, save, old_line);
/*	do_it = -1;
	while (buf[++do_it])
	{
		ft_putnbr_fd(buf[do_it], 2);
		ft_putchar_fd(' ', 2);
		}*/
	return (0);
}

int				ft_save_final_list(t_hl **hlist, char **line)
{
	int				n;
	char			buf[MAX_KEY_LEN + 1];
	t_hl			*move;
	t_save			save;
	t_sl			*list;

	list = NULL;
	save.cursor = 0;
	save.hist_nb = 0;
	save.copy = NULL;
	move = *hlist;
	ft_putstr("_$> ");
	while (save.cursor != -1)
	{
		n = -1;
		while (++n < MAX_KEY_LEN)
			buf[n] = 0;
		buf[++n] = 0;
		if (read(STDIN_FILENO, buf, MAX_KEY_LEN) == -1)
			return (-1);
		if (ft_check(buf, &list, &save, &move) == -1)
			return (-1);
	}
	if (ft_in_history(hlist, &list) == -1)
		return (-1);
	ft_list_become_chtab(line, &list);
	ft_putchar('\n');
	return (0);
}
