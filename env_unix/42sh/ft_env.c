/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:30:45 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

int		ft_exe_cmd_with_new_env(t_p *p, t_env *e)
{
	t_p		*move;
	int		i;
	t_env	*new_env;
	int		value;

	i = -1;
	value = 0;
	if (!(new_env = (t_env *)gmalloc(sizeof(t_env)))
		|| !(new_env->env = ft_copy_ts(e->env))
		|| !(new_env->env_s = ft_copy_ts(e->env_s)))
		return (-1);
	move = p;
	while (ft_find(move->tok, "="))
	{
		new_env->env[++i] = ft_strdup(move->tok);
		move = move->next;
	}
	new_env->env[++i] = NULL;
	value = ft_perform_exe(move, new_env);
	ft_free_char2(new_env->env);
	ft_free_char2(new_env->env_s);
	gfree((void *)new_env);
	return (value);
}

int		ft_find_in_env(char *str, t_p **p, t_p *save)
{
	char	*var;
	int		i;
	t_p		*move;

	move = *p;
	if (!(var = (char *)gmalloc(sizeof(char) * ft_strlen(str))))
		return (-2);
	i = -1;
	while (str[++i] != '=')
		var[i] = str[i];
	var[i] = '=';
	var[++i] = '\0';
	while (move)
	{
		if (move->tok && !ft_strncmp(var, move->tok, i))
			save = move;
		move = move->next;
	}
	gfree((void *)var);
	if (!save)
		return (-1);
	ft_putendl(save->tok);
	gfree((void *)save->tok);
	save->tok = NULL;
	return (0);
}

int		ft_display_env_modify(t_p *p, t_env *e)
{
	int		i;
	t_p		*move;
	int		ret;

	move = p;
	i = -1;
	while (e->env[++i])
	{
		if ((ret = ft_find_in_env(e->env[i], &p, NULL)) == -1)
			ft_putendl(e->env[i]);
		if (ret == -2)
			return (-1);
	}
	while (move)
	{
		if (move->tok)
			ft_putendl(move->tok);
		move = move->next;
	}
	return (0);
}

int		ft_env2(t_p *p, int modif_env, t_env *e)
{
	t_p		*move;
	int		nb_elem_new_env;

	nb_elem_new_env = 0;
	move = p;
	while (move && ft_find(move->tok, "="))
	{
		++nb_elem_new_env;
		move = move->next;
	}
	if (move && !modif_env)
		return (ft_perform_exe(p, e));
	if (!move && !modif_env)
		return (ft_display_env_modify(p, e));
	if (!move && modif_env)
	{
		move = p;
		while (move)
		{
			ft_putendl(move->tok);
			move = move->next;
		}
		return (0);
	}
	return (ft_exe_cmd_with_new_env(p, e));
}

int		ft_env(t_p *p, t_env *e)
{
	int		modif_env;
	t_p		*move;
	int		i;

	modif_env = 0;
	move = p->next;
	if (!move)
	{
		i = -1;
		while (e->env[++i])
			ft_putendl(e->env[i]);
		return (0);
	}
	while (move && !ft_strcmp(move->tok, "-i"))
	{
		move = move->next;
		++modif_env;
	}
	return (ft_env2(move, modif_env, e));
}
