/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syst_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:11:35 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 19:01:02 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_minishell3.h"
#include "libft.h"

static char		**ft_find_paths_in_env(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			if (!(paths = ft_strsplit(&env[i][5], ':')))
				return (NULL);
		}
		i++;
	}
	return (paths);
}

static char		*ft_good_path(char **all, char **env)
{
	int				i;
	char			*tmp;
	char			*str;
	char			**paths;
	struct stat		*buf;

	if (!(paths = ft_find_paths_in_env(env)))
		return (NULL);
	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (NULL);
	i = 0;
	while (paths[i])
	{
		if (!(str = (char *)gmalloc(sizeof(*str) * ft_strlen(paths[i]) + 1)))
			return (NULL);
		tmp = ft_strjoin(paths[i], "/");
		str = ft_strjoin(tmp, all[0]);
		gofree((void *)tmp);
		if (lstat(str, buf) == 0)
			return (str);
		++i;
	}
	return (all[0]);
}

char			**ft_syst_bin(char **all, char **env)
{
	int		father;
	char	*path;

	if (!(path = ft_good_path(all, env)))
		return (NULL);
	if ((father = fork()) > 0)
	{
		wait(&father);
		return (env);
	}
	if (father == 0)
	{
		if (execve(path, all, env) == -1)
		{
			ft_putendl("command not found");
			exit(-1);
		}
	}
	return (env);
}
