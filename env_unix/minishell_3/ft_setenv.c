/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:55:59 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/01 12:12:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include "libft.h"

char			**ft_setenv(char **all, char **env)
{
	if (!all[1])
		ft_ts_print(env);
	else if (!all[2])
		ft_putendl("setenv: too few arguments");
	else if (all[3])
		ft_putendl("setenv: too many arguments");
	else
	{
		if (!(env = ft_change_env(all[1], all[2], env)))
		{
			return (NULL);
		}
	}
	return (env);
}
