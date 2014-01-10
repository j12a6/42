/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:10:13 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/31 17:17:33 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "ft_pipex.h"
#include "libft.h"

static char	*ft_file_exist(char *file)
{
	DIR				*dirp;
	struct stat		*buf;

	if (!(buf = (struct stat *)malloc(sizeof(*buf))))
		return (NULL);
	dirp = opendir(".");
	if (lstat(file, buf) == -1)
		return (NULL);
	return (file);
}

static char	**ft_find_paths_in_env(char **env)
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

static char	*ft_command_exist(char *com, char **env)
{
	int				i;
	char			*str;
	char			**all_paths;
	char			**command;
	struct stat		*buf;

	command = ft_strsplit(com, ' ');
	all_paths = ft_find_paths_in_env(env);
	i = 0;
	if (!(buf = (struct stat *)malloc(sizeof(*buf))))
		return (NULL);
	while (all_paths[i])
	{
		if (!(str = (char *)malloc(sizeof(*str) * ft_strlen(all_paths[i]) + 1)))
			return (NULL);
		str = ft_strjoin(all_paths[i], "/");
		str = ft_strjoin(str, command[0]);
		if (lstat(str, buf) == 0)
			return (str);
		else if (lstat(command[0], buf) == 0)
			return (command[0]);
		i++;
	}
	return (NULL);
}

int			ft_init_struct(char **av, char **env, t_pipex *pipex, t_fd *fd)
{
	pipex->file1 = ft_file_exist(av[1]);
	if (!(pipex->file2 = (char *)malloc(sizeof(char *) * ft_strlen(av[4]) + 1)))
	{
		ft_putendl("Error");
		return (-1);
	}
	ft_strcpy(pipex->file2, av[4]);
	pipex->cmd1 = ft_command_exist(av[2], env);
	pipex->cmd2 = ft_command_exist(av[3], env);
	fd->fd1 = open(pipex->file1, O_RDONLY);
	fd->fd2 = open(pipex->file2, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
					| S_IWUSR | S_IXUSR);
	if (fd->fd1 == -1 || fd->fd2 == -1 || !pipex->file1
		|| !pipex->cmd1 || !pipex->cmd2)
	{
		ft_putendl("Error");
		return (-1);
	}
	return (1);
}
