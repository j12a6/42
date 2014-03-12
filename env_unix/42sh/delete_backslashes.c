/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_backslashes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 10:43:59 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:05 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

static int		ft_token_without_backslashes(char **tok)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = (char *)gmalloc(sizeof(char) * (ft_strlen(*tok) + 1))))
		return (-1);
	j = -1;
	i = -1;
	while ((*tok)[++i])
	{
		if ((*tok)[i] == '\\')
		{
			if ((*tok)[++i])
				ret[++j] = (*tok)[i];
			else
				return (-2);
		}
		else
			ret[++j] = (*tok)[i];
	}
	ret[++j] = '\0';
	gfree((void *)(*tok));
	*tok = ft_strdup(ret);
	gfree((void *)ret);
	return (0);
}

int				ft_delete_backslashes(t_p **p)
{
	t_p		*move;
	int		cont;

	move = *p;
	while (move)
	{
		if (move->type == WORD && ft_find(move->tok, "\\"))
		{
			if ((cont = ft_token_without_backslashes(&(move->tok))) == -2)
			{
				ft_putendl_fd("Parse error near \'\\\'", 2);
				return (-1);
			}
			else if (cont == -1)
				return (-1);
		}
		move = move->next;
	}
	return (0);
}
