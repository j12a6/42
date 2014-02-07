/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_middle_part_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:52:31 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/06 17:04:20 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

static int		ft_find_which_redir(char *str)
{
	if (!ft_strcmp(str, "<<"))
		return (1);
	else if (!ft_strcmp(str, "<"))
		return (2);
	else if (!ft_strcmp(str, ">"))
		return (3);
	else if (!ft_strcmp(str, ">>"))
		return (4);
	else
		return (-1);
}

static char		**ft_add_line_chtab(char **all)
{
	int		i;
	int		len;
	char	**cmd;

	len = ft_ts_len(all) + 1;
	if (!(cmd = (char **)gmalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	if (!(cmd[0] = ft_strdup("cat")))
		return (NULL);
	i = 0;
	while (all[i])
	{
		if (!(cmd[i + 1] = ft_strdup(all[i])))
			return (NULL);
		++i;
	}
	cmd[len] = NULL;
	return (cmd);
}

static char		**ft_cpy_chtab_untill_redir_2(char **all)
{
	int		i;
	int		n;
	char	**cmd;

	i = 0;
	while (all[i] && ft_find_which_redir(all[i]) == -1)
		++i;
	if (!(cmd = (char **)gmalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	n = i;
	i = 0;
	while (i < n)
	{
		if (!(cmd[i] = ft_strdup(all[i])))
			return (NULL);
		++i;
	}
	cmd[n] = NULL;
	return (cmd);
}

static char		**ft_cpy_chtab_untill_redir(char **all)
{
	char	**cmd;

	if (ft_find_which_redir(all[0]) != -1)
	{
		if (!(cmd = ft_add_line_chtab(all)))
			return (NULL);
	}
	if (!(cmd = ft_cpy_chtab_untill_redir_2(all)))
		return (NULL);
	return (cmd);
}

char			**ft_run_middle_part_2(char **all, char **env)
{
	char	**cmd;
	int		i;
	int		redir;

	if (!(cmd = ft_cpy_chtab_untill_redir(all)))
		return (NULL);
	i = 0;
	while (all[i] && (redir = ft_find_which_redir(all[i])) == -1)
		++i;
	if (redir == 1 || redir == 2)
	{
		if (!(env = ft_simple_left_redir(cmd, all[i + 1], env)))
			return (NULL);
	}
	else if (redir == 3)
	{
		if (!(env = ft_simple_right_redir(cmd, all[i + 1], env)))
			return (NULL);
	}
	else if (redir == 4)
	{
		if (!(env = ft_double_right_redir(cmd, all[i + 1], env)))
			return (NULL);
	}
	return (env);
 }

