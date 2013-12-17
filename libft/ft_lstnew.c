/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:30:05 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/16 20:29:18 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static t_list	*ft_nw(t_list *list, void const *content, size_t content_size)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)malloc(sizeof(*ptr) * (content_size));
	if (ptr == NULL)
		return (NULL);
	while (i < content_size)
	{
		*(ptr + i) = *((unsigned char *)content + i);
		i++;
	}
	list->content = ptr;
	list->content_size = content_size;
	return (list);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*list;

	list = (t_list *)malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
	}
	else
		ft_nw(list, content, content_size);
	list->next = NULL;
	return (list);
}
