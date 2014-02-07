/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 13:23:21 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 20:04:41 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include "ft_minishell3.h"
#include "libft.h"

static int		ft_init_terminal_mode(void)
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

int				main(int ac, char **av, char **env)
{
	t_hl		*hl;
	char		*line;
	char		**env_cp;
	int			exit;

	if (ac != 1 || !av[0] || !*env || !(env_cp = ft_ts_copy(env)))
		return (-1);
	exit = 0;
	hl = NULL;
	line = NULL;
	ft_init_terminal_mode();
	while (1)
	{
		if ((exit = ft_save_cmd_line(&hl, &line)) == -1)
			break ;
		if ((exit = ft_treat_cmd_line(line, env_cp)) == -1
			|| (exit != -2 && exit != -3))
			break ;
	}
/*	ft_default_terminal_mode();*/
	goclean();
	return (exit);
}
