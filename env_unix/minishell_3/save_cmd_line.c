/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_cmd_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 14:30:45 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 18:21:25 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <sys/ioctl.h>
#include "ft_minishell3.h"
#include "libft.h"

static int 		ft_check(char *buf, t_sl **sl, t_save *save, t_hl **hl)
{
	int					go;
	struct winsize		w;
	int					old_line;

	go = 1;
	if (KEY_ENTER(buf))
	{
		go = 0;
		save->cursor = -1;
		return (0);
	}
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	save->co = w.ws_col;
	old_line = (P_LEN + save->cursor) / save->co;
	if (go && (go = ft_put_or_del_char(buf, sl, save, hl)) == -1)
		return (-1);
	if (go && (go = ft_little_move(buf, sl, &(save->cursor), save->co)) == -1)
		return (-1);
	if (go && (go = ft_fast_move(buf, sl, &(save->cursor))) == -1)
		return (-1);
	if (go && (go = ft_move_in_history(buf, sl, save, hl)) == -1)
		return (-1);
	if (go && (go = ft_cut_copy_or_paste(buf, sl, save)) == -1)
		return (-1);
	ft_print(*sl, save, old_line);
	/*	go = -1;
		while (buf[++go])
		{
		ft_putnbr_fd(buf[go], 2);
		ft_putchar_fd(' ', 2);
		}*/
	return (0);
}

int				ft_save_cmd_line(t_hl **hl, char **line)
{
	int				n;
	char			buf[MAX_KEY_LEN + 1];
	t_hl			*move;
	t_save			save;
	t_sl			*sl;

	sl = NULL;
	save.cursor = 0;
	save.hist_nb = 0;
	save.copy = NULL;
	move = *hl;
	ft_putstr("_$> ");
	while (save.cursor != -1)
	{
		n = -1;
		while (++n < MAX_KEY_LEN)
			buf[n] = 0;
		buf[++n] = 0;
		if (read(STDIN_FILENO, buf, MAX_KEY_LEN) == -1)
			return (-1);
		if (ft_check(buf, &sl, &save, &move) == -1)
			return (-1);
	}
	if (ft_update_history(hl, sl) == -1)
		return (-1);
	ft_slist_to_ts(line, &sl);
	ft_putchar('\n');
	return (0);
}
