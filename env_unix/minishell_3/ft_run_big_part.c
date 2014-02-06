/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_big_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:19:32 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/26 21:04:23 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_minishell2.h"
#include "libft.h"

static int		ft_check_pipe(char *line)
{
	int		i;

	i = 0;
	while (*(line + i) && *(line + i + 1) && *(line + i + 2))
	{
		if (ft_isspace(*(line + i)) == 1 && *(line + i + 1) == '|'
			&& ft_isspace(*(line + i + 2)) == 1)
			return (0);
		++i;
	}
	return (-1);
}

static int		ft_indice_of_first_pipe(char *line)
{
	int		i;

	i = 0;
	while (*(line + i) && *(line + i + 1) && *(line + i + 2))
	{
		if (ft_isspace(*(line + i)) == 1 && *(line + i + 1) == '|'
			&& ft_isspace(*(line + i + 2)) == 1)
			return (i);
		++i;
	}
	return (-1);
}

static char		**ft_run_the_pipe(char *line, char **env)
{
	int		i;
	char	*cmd1;
	pid_t	father;
	int		pipe_fd[2];

	i = ft_indice_of_first_pipe(line);
	if (!(cmd1 = ft_strsub(line, 0, i)))
		return (NULL);
	if ((father = fork()) > 0)
	{
		wait(&father);
		dup2(pipe_fd[0], 0);
		if (!(env = ft_run_big_part(line + i + 1, env)))
			return (NULL);
		return (env);
	}
	if (father == 0)
	{
		dup2(pipe_fd[1], 1);
		if (!(env = ft_run_middle_part_1(cmd1, env)))
			return (NULL);
		exit(-1);
	}
	return (env);
}

char			**ft_run_big_part(char *line, char **env)
{
	if (!ft_check_pipe(line))
	{
		if (!(env = ft_run_the_pipe(line, env)))
			return (NULL);
	}
	else
	{
		if (!(env = ft_run_middle_part_1(line, env)))
			return (NULL);
	}
	return (env);
}
