/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_terminal_mode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 13:23:21 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/06 13:10:24 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_minishell3.h"

int		ft_init_terminal_mode(void)
{
	char			*term_name;
	struct termios	tattr;

	if (!(term_name = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return (-1);
	tattr.c_lflag &= ~(OPOST);
	tattr.c_lflag &= ~(ICANON);
	tattr.c_lflag &= ~(ECHO);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr) == -1)
		return (-1);
	return (0);
}

int		ft_default_terminal_mode(void)
{
	struct termios	tattr;

	if (tcgetattr(STDIN_FILENO, &tattr) == -1)
		return (-1);
	tattr.c_lflag |= ~(OPOST);
	tattr.c_lflag |= ~(ICANON);
	tattr.c_lflag |= ~(ECHO);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr) == -1)
		return (-1);
	return (0);
}

int		main(void)
{
	t_hl		*hlist;
	char		*line;

	hlist = NULL;
	line = NULL;
	ft_init_terminal_mode();
	if (ft_save_final_list(&hlist, &line) == -1)
		return (-1);
	if (ft_save_final_list(&hlist, &line) == -1)
		return (-1);
	if (ft_save_final_list(&hlist, &line) == -1)
		return (-1);
	ft_default_terminal_mode();
	return (0);
}
