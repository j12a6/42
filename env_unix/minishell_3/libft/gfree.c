/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:46:31 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/07 11:09:45 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_free_one_elem(void *ptr, t_list **list)
{
	t_list		*first;
	t_list		*tmp;

	first = *list;
	while (first && first->next)
	{
		if (first->next->content == ptr)
		{
			tmp = first->next;
			free(first->next->content);
			first->next = first->next->next;
			free((void *)tmp);
			break ;
		}
		first = first->next;
	}
}

void	gfree(void *ptr, t_list **list)
{
	t_list		*first;

	first = *list;
	if (first && !(first->next))
	{
		free(first->content);
		free((void *)first);
		*list = NULL;
		return ;
	}
	if (first && first->content == ptr)
	{
		*list = (*list)->next;
		free(first->content);
		free((void *)first);
	}
	else
	{
		ft_free_one_elem(ptr, list);
	}
}
