/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 12:38:52 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/25 21:39:30 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_pipex.h"
#include "libft.h"

int		ft_run(char **av, char **env, t_fd *fd, t_pipex *pipex)
{
	int			father;
	int			pipe_fd[2];
	char		**opt1;
	char		**opt2;

	opt1 = ft_strsplit(av[2], ' ');
	opt2 = ft_strsplit(av[3], ' ');
	pipe(pipe_fd);
	if ((father = fork()) > 0)
	{
		dup2(fd->fd1, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		execve(pipex->cmd1, opt1, env);
		return (0);
	}
	if (father == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		dup2(fd->fd2, 1);
		execve(pipex->cmd2, opt2, env);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av, char **env)
{
	t_fd		*fd;
	t_pipex		*pipex;

	if (ac != 5)
	{
		ft_putendl("Error: too many or missing arguments");
		return (-1);
	}
	if (!(pipex = (t_pipex *)malloc(sizeof(*pipex)))
		|| !(fd = (t_fd *)malloc(sizeof(*fd))))
		return (-1);
	if (ft_init_struct(av, env, pipex, fd) == -1)
		return (-1);
	ft_run(av, env, fd, pipex);
	return (0);
}
