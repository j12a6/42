/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 22:04:02 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/09 16:40:59 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell3.h"

int			ft_slist_len(t_sl *sl)
{
	int		i;
	t_sl	*move;

	move = sl;
	i = 0;
	while (move)
	{
		++i;
		move = move->next;
	}
	return (i);
}

int			ft_hlist_len(t_hl *hl)
{
	int		i;
	t_hl	*move;

	move = hl;
	i = 0;
	while (move)
	{
		++i;
		move = move->next;
	}
	return (i);
}
