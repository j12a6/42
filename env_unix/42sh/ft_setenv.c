/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:44:10 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:47 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "sh.h"

int		ft_change_value_variable(char *var, char *val, char ***env)
{
	int		i;

	i = 0;
	while ((*env)[i] && ft_strncmp((*env)[i], var, ft_strlen(var)))
		++i;
	if (!((*env)[i]))
		return (-1);
	gfree((*env)[i]);
	(*env)[i] = val ? ft_strjoin(var, val) : ft_strdup(var);
	return (0);
}

int		ft_add_var(char *var, char *val, char ***env)
{
	int		i;
	char	**new_env;
	char	*new_line;

	new_line = NULL;
	i = 0;
	while ((*env)[i])
		++i;
	if (!(new_env = gmalloc(sizeof(char *) * (i + 2))))
		return (-1);
	i = -1;
	while ((*env)[++i])
		new_env[i] = (char *)c_calls("dup", (void *)(*env)[i]);
	gfree((void *)*env);
	new_line = ft_strjoin(var, "=");
	new_env[i] = val ? ft_strjoin(new_line, val) : ft_strdup(new_line);
	new_env[++i] = NULL;
	gfree(new_line);
	*env = new_env;
	return (0);
}

int		ft_replace_or_add(t_p *move, char ***env)
{
	if (move->next)
	{
		if (ft_change_value_variable(ft_strjoin(move->tok, "="),
										move->next->tok, env) == -1)
		{
			if (ft_add_var(move->tok, move->next->tok, env) == -1)
				return (-1);
		}
		return (0);
	}
	else
	{
		if (ft_change_value_variable(ft_strjoin(move->tok, "="),
										NULL, env) == -1)
		{
			if (ft_add_var(move->tok, NULL, env) == -1)
				return (-1);
		}
	}
	return (0);
}

int		ft_setenv(t_p *p, char ***env)
{
	t_p		*move;
	int		i;

	move = p->next;
	if (!move)
	{
		i = -1;
		while ((*env)[++i])
			ft_putendl((*env)[i]);
		return (0);
	}
	if (move->next && move->next->next)
		return (ft_error_msg("setenv: Too many arguments.", ""));
	if (ft_find(move->tok, "=")
		|| (move->next && ft_find(move->next->tok, "=")))
		return (ft_error_msg("setenv: Avoid the character '='", ""));
	return (ft_replace_or_add(move, env));
}
