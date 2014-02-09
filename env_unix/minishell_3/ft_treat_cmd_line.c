/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cmd_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:26:49 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/09 18:28:44 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

char	**ft_treat_cmd_line(char *line, char **env, int *exit)
{
	int		i;
	char	**all;

	if (!(all = ft_strsplit(line, ';')))
		return (NULL);
	*exit = -2;
	i = -1;
	while (all[++i])
	{
		all[i] = ft_strtrim(all[i]);
		if ((*exit = ft_my_sh_exit(all[i])) == -1 || *exit == -3)
			break ;
		if (*exit == -2)
		{
			if (all[i][0] && !(env = ft_run_big_part(all[i], env)))
			{
				*exit = -2;
				break ;
			}
		}
	}
	return (env);
}
