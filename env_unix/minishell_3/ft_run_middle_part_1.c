/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_middle_part_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:33:02 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 20:36:10 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

static int		ft_is_redir(char *str)
{
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, "<")
		|| !ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (0);
	return (-1);
}

static int		ft_check_redir(char **all)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (all[i])
	{
		if (!ft_is_redir(all[i]))
			++nb;
		++i;
	}
	return (nb);
}

static int		ft_check_only_one_file(char **all)
{
	int		i;
	int		nb_lines;

	nb_lines = ft_ts_len(all);
	i = 0;
	while (all[i] && ft_is_redir(all[i]) != 0)
		++i;
	if (all[i] && nb_lines != i + 2)
		return (0);
	return (1);
}

char			**ft_run_middle_part_1(char *line, char **env)
{
	char	**all;

	if (!(all = ft_strparse(line)))
		return (NULL);
	if (ft_check_redir(all) > 1 || !ft_check_only_one_file(all))
		ft_putendl("ambigous redirection");
	else if (ft_check_redir(all) == 1)
	{
		if (!(env = ft_run_middle_part_2(all, env)))
			return (NULL);
	}
	else
	{
		if (!(env = ft_run_small_part(line, env)))
			return (NULL);
	}
	return (env);
}
