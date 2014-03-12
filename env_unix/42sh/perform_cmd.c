/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 11:40:58 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:09:50 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft.h"
#include "sh.h"

char		*ft_not_need_variable_env_path(char *cmd)
{
	struct stat		*buf;

	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (NULL);
	if (lstat(cmd, buf) == 0
		&& buf->st_mode & S_IXUSR && !(buf->st_mode & S_IFDIR)
		&& (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/')))
	{
		gfree(buf);
		return (cmd);
	}
	gfree(buf);
	return (NULL);
}

char		*ft_find_the_path(char *cmd, char **paths)
{
	char			*good_path;
	struct stat		*buf;
	int				i;

	good_path = NULL;
	buf = NULL;
	if ((good_path = ft_not_need_variable_env_path(cmd)))
		return (good_path);
	i = -1;
	while (paths[++i])
	{
		if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
			return (NULL);
		good_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (lstat(good_path, buf) == 0 && buf->st_mode & S_IXUSR)
		{
			gfree(buf);
			return (good_path);
		}
		gfree(good_path);
		gfree(buf);
	}
	return (NULL);
}

int			ft_perform_exe(t_p *p, t_env *e)
{
	char	**paths;
	char	*good_path;
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (e->env[i] && ft_strncmp(e->env[i], "PATH=", 5))
		++i;
	if (!e->env[i])
		paths = ft_strsplit(&(e->env_s[0][5]), ':');
	else
		paths = ft_strsplit(&(e->env[i][5]), ':');
	if (!(good_path = ft_find_the_path(p->tok, paths)))
	{
		ft_free_char2(paths);
		return (ft_error_msg(p->tok, ": Command not found"));
	}
	value = ft_exe_the_cmd(p, good_path, e->env);
	gfree(good_path);
	ft_free_char2(paths);
	return (value);
}

int			ft_perform_cmd(t_tree *t, t_env *e)
{
	int		value;

	value = 0;
	if (!ft_strcmp(t->p->tok, "exit"))
		value = ft_exit(t->p);
	else if (!ft_strcmp(t->p->tok, "echo"))
		ft_echo(t->p);
	else if (!(ft_strcmp(t->p->tok, "cd")))
		value = ft_cd(t->p, e);
	else if (!(ft_strcmp(t->p->tok, "env")))
		value = ft_env(t->p, e);
	else if (!(ft_strcmp(t->p->tok, "unsetenv")))
		value = ft_unsetenv(t->p, &(e->env));
	else if (!(ft_strcmp(t->p->tok, "setenv")))
		value = ft_setenv(t->p, &(e->env));
	else
		value = ft_perform_exe(t->p, e);
	return (value);
}
