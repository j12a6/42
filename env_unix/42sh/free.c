/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 11:55:12 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:48 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

void		ft_free_list(t_p *move)
{
	while (move && move->next)
	{
		move = move->next;
		if (move->prev->tok)
			gfree((void *)move->prev->tok);
		gfree((void *)move->prev);
	}
	if (move && move->tok)
		gfree((void *)move->tok);
	if (move)
		gfree((void *)move);
}

void		ft_free_tree(t_tree **t)
{
	if ((*t)->le)
		ft_free_tree(&((*t)->le));
	if ((*t)->ri)
		ft_free_tree(&((*t)->ri));
	ft_free_list((*t)->p);
	gfree((void *)*t);
}
