/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 15:35:56 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 15:30:31 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*ft_listnew(void *ptr)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = ptr;
	list->next = NULL;
	return (list);
}

int				ft_garb(int flag, void *ptr)
{
	static t_list	*list = NULL;
	t_list			*tmp;

	if (!list && flag == 2)
	{
		if (!(list = ft_listnew(ptr)))
			return (-1);
		return (0);
	}
	if (flag == 0)
	{
		gclean(&list);
		return (-1);
	}
	else if (flag == 1)
		gfree(ptr, &list);
	else
	{
		if (!(tmp = ft_listnew(ptr)))
			return (-1);
		tmp->next = list;
		list = tmp;
	}
	return (0);
}
