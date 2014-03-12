/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_all_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 10:48:13 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/05 14:16:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft.h"
#include "sh.h"

static int		ft_exe_redir(t_tree *t, t_env *e, int fd)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (0);
	}
	else
	{
		if (t->p->type == RED_R || t->p->type == RED_DR)
			dup2(fd, 1);
		else
		{
			ft_putendl_fd("AAAA", 2);
			dup2(fd, 0);
		}
		*ft_value() = ft_execute_all(t->le, e);
		close(fd);
		exit(1);
	}
	return (0);
}

int				ft_perform_redir(t_tree *t, t_env *e)
{
	int		fd;
	int		value;

	value = 0;
	if (t->ri->le || t->ri->ri || t->ri->p->next)
	{
		ft_putendl_fd("Invalid null command", 2);
		return (-1);
	}
	if (t->p->type == RED_R
		&& ((fd = open(t->ri->p->tok,
						O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1))
		return (ft_error_msg(t->ri->p->tok, ": open impossible"));
	else if (t->p->type == RED_L
			&& ((fd = open(t->ri->p->tok, O_RDONLY)) == -1))
		return (ft_error_msg(t->ri->p->tok, ": open impossible"));
	else if (t->p->type == RED_DR
			&& (fd = open(t->ri->p->tok, O_APPEND | O_WRONLY)) == -1)
		return (ft_error_msg(t->ri->p->tok, ": open impossible"));
	ft_exe_redir(t, e, fd);
	value = *ft_value();
	return (value);
}

int				ft_perform_pipe2(t_tree *t, t_env *e)
{
	int		fd_pipe[2];
	pid_t	father;
	int		value;

	value = 0;
	pipe(fd_pipe);
	father = fork();
	if (father == 0)
	{
		dup2(fd_pipe[0], 0);
		close(fd_pipe[1]);
		*ft_value() = ft_execute_all(t->ri, e);
	}
	else
	{
		dup2(fd_pipe[1], 1);
		close(fd_pipe[0]);
		*ft_value() = ft_execute_all(t->le, e);
	}
	value = *ft_value();
	return (value);
}

int				ft_perform_pipe(t_tree *t, t_env *e)
{
	pid_t	father;
	int		value;

	value = 0;
	father = fork();
	if (father > 0)
		wait(&father);
	else
	{
		value = ft_perform_pipe2(t, e);
		exit(1);
	}
	value = *ft_value();
	return (value);
}
