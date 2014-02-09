/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:41:17 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/09 18:31:56 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

static int		ft_compare_key(char *my_key, char *key_val)
{
	int		k;

	k = 0;
	while (key_val[k] && key_val[k] != '=')
		++k;
	if (!ft_strncmp(my_key, key_val, k))
		return (0);
	return (-1);
}

static int		ft_key_already_exist(char *my_key, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_compare_key(my_key, env[i]))
			return (0);
		++i;
	}
	return (1);
}

static char		*ft_put_my_env_line(char *my_key, char *my_val)
{
	char	*str;
	char	*tmp;

	if (!(tmp = ft_strjoin(my_key, "=")))
		return (NULL);
	if (!(str = ft_strjoin(tmp, my_val)))
		return (NULL);
	gofree((void *)tmp);
	return (str);
}

static char		*ft_new_env_line(char *my_key, char *my_val, char *key_val)
{
	char	*str;

	if (!ft_compare_key(my_key, key_val))
	{
		if (!(str = ft_put_my_env_line(my_key, my_val)))
			return (NULL);
	}
	else if (!(str = ft_strdup(key_val)))
		return (NULL);
	return (str);
}

char			**ft_change_env(char *my_key, char *my_val, char **env)
{
	int		i;
	int		nb_lines;
	char	**new_env;

	if (!my_key || !my_val || !env)
		return (NULL);
	nb_lines = ft_ts_len(env);
	if (!(new_env = (char **)gmalloc(sizeof(char *)	* (nb_lines
		+ ft_key_already_exist(my_key, env) + 1))))
		return (NULL);
	i = 0;
	while (i < nb_lines)
	{
		new_env[i] = ft_new_env_line(my_key, my_val, env[i]);
		++i;
	}
	if (ft_key_already_exist(my_key, env) == 1)
	{
		if (!(new_env[i] = ft_put_my_env_line(my_key, my_val)))
			return (NULL);
	}
	new_env[nb_lines + ft_key_already_exist(my_key, env)] = NULL;
	return (new_env);
}
