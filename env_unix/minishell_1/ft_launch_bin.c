/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 12:11:35 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/15 14:19:24 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_minishell1.h"
#include "libft.h"

static char		*ft_bin_wanted(char *line)
{
	int		i;
	char	*com_name;

	if (!(com_name = (char *)malloc(sizeof(*com_name) * ft_strlen(line) + 1)))
		return (NULL);
	i = 0;
	while (*(line + i) && *(line + i) != ' ')
	{
		*(com_name + i) = *(line + i);
		i++;
	}
	*(com_name + i) = '\0';
	return (com_name);
}

static char		**ft_find_paths_in_env(char **env)
{
	int		i;
	char	**all_paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			all_paths = ft_strsplit(&env[i][5], ':');
		i++;
	}
	return (all_paths);
}

static char		*ft_good_path(char *line, char **env)
{
	int				i;
	char			*str;
	char			**all_paths;
	char			*com_name;
	struct stat		*buf;

	com_name = ft_bin_wanted(line);
	all_paths = ft_find_paths_in_env(env);
	i = 0;
	if (!(buf = (struct stat *)malloc(sizeof(*buf))))
		return (NULL);
	while (all_paths[i])
	{
		if (!(str = (char *)malloc(sizeof(*str)
			* ft_strlen(all_paths[i]) + 1000)))
			return (NULL);
		str = ft_strjoin(all_paths[i], "/");
		str = ft_strjoin(str, com_name);
		if (lstat(str, buf) == 0)
			return (str);
		i++;
	}
	return (NULL);
}

int				ft_launch_bin(char *line, char **env)
{
	char	**tab;
	int		father;
	char	*path;

	path = ft_good_path(line, env);
	tab = ft_strsplit(line, ' ');
	if (path == NULL)
	{
		ft_putendl("command not found");
		return (0);
	}
	father = fork();
	if (father > 0)
	{
		wait(&father);
		ft_free_char2(tab);
		return (0);
	}
	if (father == 0)
		execve(path, tab, env);
	return (1);
}
