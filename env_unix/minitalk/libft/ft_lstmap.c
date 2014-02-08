/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 20:28:56 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 13:16:43 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*tmp;
	t_list	*map2;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	tmp = f(tmp);
	if (!(map = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	map2 = map;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = lst;
		tmp = f(tmp);
		if (!(map->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		map = map->next;
		lst = lst->next;
	}
	return (map2);
}
