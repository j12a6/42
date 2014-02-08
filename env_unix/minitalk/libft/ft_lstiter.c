/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 19:06:47 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 13:49:34 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*iter;

	if (lst == NULL)
		return ;
	iter = lst;
	while (lst != NULL)
	{
		f(iter);
		lst = lst->next;
		iter = lst;
	}
}
