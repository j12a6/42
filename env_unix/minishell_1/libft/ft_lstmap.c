/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:20:14 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/01 17:50:02 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*f_list;
	t_list	*temp;
	t_list	*begin;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	temp = f(temp);
	f_list = ft_lstnew(temp->content, temp->content_size);
	if (f_list == NULL)
		return (NULL);
	begin = f_list;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = lst;
		temp = f(temp);
		f_list->next = ft_lstnew(temp->content, temp->content_size);
		if (f_list == NULL)
			return (NULL);
		f_list = f_list->next;
		lst = lst->next;
	}
	return (begin);
}
