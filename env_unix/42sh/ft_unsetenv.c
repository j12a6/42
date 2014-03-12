/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:05:01 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

void		ft_del_var(char *var, char ***env)
{
	int		i;

	i = 0;
	while ((*env)[i] && ft_strncmp((*env)[i], var, ft_strlen(var)))
		++i;
	if (!((*env)[i]))
		return ;
	while ((*env)[i + 1])
	{
		gfree((*env)[i]);
		(*env)[i] = ft_strdup((*env)[i + 1]);
		++i;
	}
	gfree((*env)[i]);
	(*env)[i] = NULL;
	return ;
}

int			ft_unsetenv(t_p *p, char ***env)
{
	t_p		*move;

	move = p->next;
	if (!move)
		ft_putendl_fd("unsetenv: Too few arguments", 2);
	while (move)
	{
		while (ft_find(move->tok, "="))
			move = move->next;
		if (move)
			ft_del_var(move->tok, env);
		move = move->next;
	}
	return (0);
}
