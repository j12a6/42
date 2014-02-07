/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cmd_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:26:49 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 20:49:55 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

int		ft_treat_cmd_line(char *line, char **env)
{
	int		i;
	char	**all;
	int		exit;

	if (!(all = ft_strsplit(line, ';')))
		return (-1);
	exit = -2;
	i = -1;
	while (all[++i])
	{
		all[i] = ft_strtrim(all[i]);
		if (((exit = ft_my_sh_exit(all[i])) == -1 || exit != -2) && exit != -3)
			break ;
		if (exit == -2)
		{
			if (all[i][0] && !(env = ft_run_big_part(all[i], env)))
			{
				exit = -2;
				break ;
			}
		}
	}
	return (exit);
}
