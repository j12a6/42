/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 11:43:48 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/29 21:12:29 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "libft.h"

void	ft_env(char *line, char **env)
{
	int		n;
	char	**tab;
	int		only_env;

	tab = ft_strsplit(line, ' ');
	n = 0;
	only_env = 1;
	while (tab[n] && only_env == 1)
	{
		if (ft_strcmp(tab[n], "env") != 0)
			only_env = 0;
		n++;
	}
	n = 0;
	if (only_env == 1)
	{
		while (env[n])
		{
			ft_putendl(env[n]);
			n++;
		}
	}
	else
		ft_putendl("env: no such file or directory");
	ft_free_char2(tab);
}
