/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:02:23 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 13:17:29 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*ft_new(void const *content, size_t content_size, t_list *new)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (!(ptr = (unsigned char *)gmalloc(sizeof(*ptr) * content_size)))
		return (NULL);
	while (i < content_size)
	{
		*(ptr + i) = *((unsigned char *)content + i);
		i++;
	}
	new->content = ptr;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new;

	if (!(new = (t_list *)gmalloc(sizeof(*new))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	return (ft_new(content, content_size, new));
}
