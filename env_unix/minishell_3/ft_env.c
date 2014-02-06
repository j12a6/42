/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 11:43:48 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/01 12:11:19 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include "libft.h"

static int	ft_only_env(char **all)
{
	int		i;

	i = 0;
	while (all[i])
	{
		if (ft_strcmp(all[i], "env") != 0)
			return (-1);
		++i;
	}
	return (0);
}

void		ft_env(char **all, char **env)
{
	if (!ft_only_env(all))
		ft_ts_print(env);
	else if (all[1])
		ft_putendl("env: No such file or directory");
}
