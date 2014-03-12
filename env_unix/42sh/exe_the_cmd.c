/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_the_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:58:06 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:27 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh.h"
#include "libft.h"

char		**ft_create_the_line_of_cmd(t_p *p)
{
	t_p		*move;
	char	*line_of_cmd;

	line_of_cmd = ft_strdup(p->tok);
	move = p->next;
	while (move)
	{
		line_of_cmd = c_calld("join", line_of_cmd, " ");
		line_of_cmd = c_calld("join", line_of_cmd, move->tok);
		move = move->next;
	}
	return (ft_strsplit(line_of_cmd, ' '));
}

int			ft_exe_the_cmd(t_p *p, char *path, char **env)
{
	char	**line_of_cmd;
	pid_t	father;

	line_of_cmd = ft_create_the_line_of_cmd(p);
	*ft_value() = 0;
	father = fork();
	if (father > 0)
	{
		wait(&father);
		return (*ft_value());
	}
	else
	{
		execve(path, line_of_cmd, env);
		ft_putstr_fd(p->tok, 2);
		ft_putendl_fd(": Command not found", 2);
		*ft_value() = -1;
		exit(1);
	}
	return (*ft_value());
}
