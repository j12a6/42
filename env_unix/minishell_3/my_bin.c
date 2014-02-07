/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 15:31:08 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/06 16:58:45 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

void	ft_my_bin_1(char **all, char **env)
{
	if (!ft_strcmp(all[0], "pwd"))
		ft_pwd(all);
	else if (!ft_strcmp(all[0], "env"))
		ft_env(all, env);
}

char	**ft_my_bin_2(char **all, char **env)
{
	if (!ft_strcmp(all[0], "cd"))
	{
		if (!(env = ft_cd(all, env)))
			return (NULL);
	}
	else if (!ft_strcmp(all[0], "setenv"))
	{
		if (!(env = ft_setenv(all, env)))
			return (NULL);
	}
	else if (!ft_strcmp(all[0], "unsetenv"))
	{
		if (!(env = ft_unsetenv(all, env)))
			return (NULL);
	}
	return (env);
}
