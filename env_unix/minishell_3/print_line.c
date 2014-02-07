/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:01:20 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 12:43:46 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "ft_minishell3.h"
#include "libft.h"

static void		ft_slist_print(t_sl *sl, int co)
{
	int		i;

	i = P_LEN;
	while (sl)
	{
		ft_putchar_fd(sl->c, 2);
		sl = sl->next;
		++i;
		if (i % co == 0)
			tputs(tgetstr("do", NULL), 1, ft_putc);
	}
}

static int		ft_clean(int old_line, int cursor_line)
{
	int		i;

	i = old_line;
	while (i < cursor_line)
	{
		tputs(tgetstr("do", NULL), 1, ft_putc);
		++i;
	}
	while (i > cursor_line)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		--i;
	}
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_putc);
	return (0);
}

int				ft_print(t_sl *sl, t_save *save, int old_line)
{
	int		cursor_line;
	int		i;

	cursor_line = (P_LEN + save->cursor) / save->co;
	ft_clean(old_line, cursor_line);
	i = cursor_line;
	while (i > 0)
	{
		tputs(tgetstr("up", NULL), 1, ft_putc);
		--i;
	}
	tputs(tgetstr("cd", NULL), 1, ft_putc);
	ft_putstr("_$> ");
	ft_slist_print(sl, save->co);
	if (save->cursor != ft_slist_len(sl))
	{
		tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + save->cursor) % save->co), 1, ft_putc);
		i = (P_LEN + ft_slist_len(sl)) / save->co;
		while (i > cursor_line)
		{
			tputs(tgetstr("up", NULL), 1, ft_putc);
			--i;
		}
	}
	return (0);
}
