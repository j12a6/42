/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 11:07:53 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/06 16:16:49 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_minishell3.h"
#include "libft.h"

static char		*ft_find_home(char **env)
{
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "HOME=", 5) != 0)
		++i;
	return (env[i] + 5);
}

static char		*ft_find_oldpwd(char **env)
{
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "OLDPWD=", 7) != 0)
		++i;
	return (env[i] + 7);
}

char			**ft_cd(char **all, char **env)
{
	char	*cur_dir;
	char	*buf;
	int		success;

	success = 0;
	if (!(buf = (char *)gmalloc(sizeof(char) * (2048 + 1))))
		return (NULL);
	cur_dir = getcwd(buf, 1024);
	if (!all[1])
	{
		if (chdir(ft_find_home(env)) == -1)
			ft_putendl_fd("cd: error going to home directory", 2);
		success = 1;
	}
	else if (all[2])
		ft_putendl("cd: too many arguments");
	else if (!ft_strcmp(all[1], "-"))
	{
		if (chdir(ft_find_oldpwd(env)) == -1)
			ft_putendl_fd("cd: error going to last directory", 2);
		success = 1;
	}
	else if (!chdir(all[1]))
		success = 1;
	else
		ft_putendl("cd: not a directory");
	if (success == 1)
	{
		if (!(env = ft_change_env("OLDPWD", cur_dir, env)))
			return (NULL);
		if (!(env = ft_change_env("PWD", getcwd(buf, 1024), env)))
			return (NULL);
	}
	return (env);
}
