/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:26:49 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/15 17:48:31 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell1.h"
#include "libft.h"

int			main(int ac, char **av, char **env)
{
	char		*line;
	char		**env_copy;

	ac = 0;
	av[0] = "allez";
	env_copy = ft_cpy_char2(env);
	ft_putstr("jaubert$> ");
	while (get_next_line(0, &line) && ft_strcmp(line, "exit") != 0)
	{
		if (ft_strcmp(line, "pwd") == 0)
			ft_pwd();
		else if (ft_strncmp(line, "cd", 2) == 0)
			ft_cd(line);
		else if (ft_strncmp(line, "env", 3) == 0)
			ft_env(line, env_copy);
		else if (ft_strncmp(line, "setenv", 6) == 0)
			env_copy = ft_setenv(line, env_copy);
		else if (line)
			ft_launch_bin(line, env_copy);
		ft_putstr("jaubert$> ");
		free(line);
	}
	return (0);
}
