/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:01:20 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/05 19:34:43 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft.h"
#include "ft_minishell3.h"

static void		ft_slist_print(t_sl *list, int co)
{
	int		i;

	i = P_LEN;
	while (list)
	{
		ft_putchar_fd(list->c, 2);
		list = list->next;
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

int				ft_print(t_sl *list, t_save *save, int old_line)
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
	ft_slist_print(list, save->co);
	if (save->cursor != ft_slist_len(list))
	{
		tputs(tgoto(tgetstr("ch", NULL), 0, (P_LEN + save->cursor) % save->co), 1, ft_putc);
		i = (P_LEN + ft_slist_len(list)) / save->co;
		while (i > cursor_line)
		{
			tputs(tgetstr("up", NULL), 1, ft_putc);
			--i;
		}
	}
	return (0);
}
