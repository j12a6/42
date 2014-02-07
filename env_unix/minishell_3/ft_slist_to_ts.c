/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_to_ts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 12:45:47 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 14:17:42 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"
#include "libft.h"

int		ft_slist_to_ts(char **line, t_sl **sl)
{
	int		i;
	t_sl	*move;

	i = 0;
	move = *sl;
	while (move)
	{
		++i;
		move = move->next;
	}
	if (*line)
		gofree((void *)*line);
	if (!(*line = (char *)gmalloc(sizeof(char) * (i + 1))))
		return (-1);
	i = -1;
	move = *sl;
	while (move)
	{
		(*line)[++i] = move->c;
		move = move->next;
		gofree((void *)*sl);
		*sl = move;
	}
	(*line)[++i] = '\0';
	return (0);
}
