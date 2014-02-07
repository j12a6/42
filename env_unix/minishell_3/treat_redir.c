/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 10:02:50 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 11:59:12 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_minishell3.h"
#include "libft.h"

char			**ft_simple_left_redir(char **cmd, char *file, char **env)
{
	int		father;
	int		fd;
	char	*line;
	char	**all;

	line = ft_ts_to_str(cmd);
	if (!(all = ft_strparse(line)))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_putendl("file open failed or file does not exist");
	if ((father = fork()) > 0)
	{
		wait(&father);
		return (env);
	}
	if (father == 0)
	{
		dup2(fd, 0);
		if (!(env = ft_run_small_part(line, env)))
			return (NULL);
		exit(-1);
	}
	return (env);
}

char			**ft_simple_right_redir(char **cmd, char *file, char **env)
{
	pid_t	father;
	int		fd;
	char	*line;
	char	**all;

	line = ft_ts_to_str(cmd);
	if (!(all = ft_strparse(line)))
		return (NULL);
	if ((fd = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
					| S_IWUSR | S_IRUSR)) == -1)
		ft_putendl("file open failed");
	if ((father = fork()) > 0)
	{
		wait(&father);
		return (env);
	}
	if (father == 0)
	{
		dup2(fd, 1);
		if (!(env = ft_run_small_part(line, env)))
			return (NULL);
		exit(-1);
	}
	return (env);
}

char			**ft_double_right_redir(char **cmd, char *file, char **env)
{
	pid_t	father;
	int		fd;
	char	*line;
	char	**all;

	line = ft_ts_to_str(cmd);
	if (!(all = ft_strparse(line)))
		return (NULL);
	if ((fd = open(file, O_RDWR | O_CREAT | O_APPEND, S_IRUSR
					| S_IWUSR | S_IRUSR)) == -1)
		ft_putendl("file open failed");
	if ((father = fork()) > 0)
	{
		wait(&father);
		return (env);
	}
	if (father == 0)
	{
		dup2(fd, 1);
		if (!(env = ft_run_small_part(line, env)))
			return (NULL);
		exit(-1);
	}
	return (env);
}

