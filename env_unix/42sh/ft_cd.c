/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:47:33 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:53 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "sh.h"
#include "libft.h"

int			ft_return_last_rep(t_env *e, char *old_pwd)
{
	int		i;
	char	*pwd;

	pwd = NULL;
	i = 0;
	while (e->env[i] && ft_strncmp(e->env[i], "OLDPWD=", 7))
		++i;
	if (!(e->env[i]) || (chdir(&(e->env[i][7])) == -1))
		return (ft_error_msg(": No such file or directory", ""));
	pwd = getcwd(pwd, 0);
	ft_change_value_variable("PWD=", pwd, &(e->env));
	ft_change_value_variable("PWD=", pwd, &(e->env_s));
	ft_change_value_variable("OLDPWD=", old_pwd, &(e->env));
	return (0);
}

int			ft_return_home(t_env *e, char *old_pwd)
{
	char	*pwd;
	int		i;

	pwd = NULL;
	i = 0;
	while (e->env[i] && ft_strncmp(e->env[i], "HOME=", 5))
		++i;
	if (!(e->env[i]))
		return (ft_error_msg("cd: No home directory", ""));
	if (chdir(&(e->env[i][5])) == -1)
		return (ft_error_msg("cd: Can't change to home directory", ""));
	pwd = getcwd(pwd, 0);
	ft_change_value_variable("PWD=", pwd, &(e->env));
	ft_change_value_variable("PWD=", pwd, &(e->env_s));
	ft_change_value_variable("OLDPWD=", old_pwd, &(e->env));
	return (0);
}

char		*ft_change_pwd(char *rep, char *old_pwd)
{
	int		len;
	char	*new_pwd;

	new_pwd = NULL;
	len = ft_strlen(old_pwd) - 1;
	if (len < 0)
		return (old_pwd);
	while (len >= 0 && old_pwd[len] != '/')
		--len;
	if (len <= 0)
		return (old_pwd);
	new_pwd = ft_strjoin(ft_strsub(old_pwd, 0, len + 1), rep);
	gfree(old_pwd);
	return (new_pwd);
}

int			ft_go_to_rep(char *rep, t_env *e, char *old_pwd, int flag)
{
	char			*pwd;
	struct stat		*buf;
	int				value1;
	int				value2;

	pwd = NULL;
	if (!(buf = (struct stat *)gmalloc(sizeof(*buf))))
		return (-1);
	value1 = chdir(rep);
	value2 = lstat(rep, buf);
	if (value1 == -1 && value2 == 0
		&& (buf->st_mode & S_IFDIR || buf->st_mode & S_IFLNK))
		return (ft_error_msg(rep, ": Permission denied"));
	else if (value1 == -1 && value2 == 0)
		return (ft_error_msg(rep, ": Not a directory"));
	else if (value1 == -1 && value2 == -1)
		return (ft_error_msg(rep, ": No such file or directory"));
	pwd = getcwd(pwd, 0);
	if (rep[0] != '.' && flag == 0)
		pwd = ft_change_pwd(rep, pwd);
	ft_change_value_variable("PWD=", pwd, &(e->env));
	ft_change_value_variable("PWD=", pwd, &(e->env_s));
	ft_change_value_variable("OLDPWD=", old_pwd, &(e->env));
	return (0);
}

int			ft_cd(t_p *p, t_env *e)
{
	int		value;
	char	*buf;

	value = 0;
	buf = NULL;
	buf = getcwd(buf, 0);
	if (!p->next
		|| (p->next && !ft_strcmp(p->next->tok, "-P") && !p->next->next))
		value = ft_return_home(e, buf);
	else if ((p->next->next && p->next->tok[0] != '-')
			|| (p->next->next && p->next->next->next))
		value = ft_error_msg("cd: Too many arguments", "");
	else if (!ft_strcmp(p->next->tok, "-"))
		value = ft_return_last_rep(e, buf);
	else if (!ft_strcmp(p->next->tok, "-P"))
		value = ft_go_to_rep(p->next->next->tok, e, buf, 1);
	else if (!ft_strcmp(p->next->tok, "-L"))
		value = ft_go_to_rep(p->next->next->tok, e, buf, 0);
	else if (p->next->tok[0] == '-')
		value = ft_error_msg("Usage: cd [-L|-P][dir]", "");
	else
		value = ft_go_to_rep(p->next->tok, e, buf, 0);
	free(buf);
	return (value);
}
