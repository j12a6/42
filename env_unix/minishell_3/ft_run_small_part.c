/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_small_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:16:57 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/09 19:31:33 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

static int		ft_check_my_bin_1(char *cmd)
{
	if (!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "env"))
		return (0);
	return (-1);
}

static int		ft_check_my_bin_2(char *cmd)
{
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "setenv")
		|| !ft_strcmp(cmd, "unsetenv"))
		return (0);
	return (-1);
}

char			**ft_run_small_part(char *line, char **env)
{
	char	**all;

	if (!(all = ft_strparse(line)))
		return (NULL);
	if (!ft_check_my_bin_1(all[0]))
		ft_my_bin_1(all, env);
	else if (!ft_check_my_bin_2(all[0]))
	{
		if (!(env = ft_my_bin_2(all, env)))
			return (NULL);
	}
	else
	{
		if (!(env = ft_syst_bin(all, env)))
			return (NULL);
	}
	return (env);
}
