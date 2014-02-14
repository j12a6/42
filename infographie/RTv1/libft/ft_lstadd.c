/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:04:05 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/12 13:48:29 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (new->next != NULL)
			new = new->next;
		new->next = *alst;
		*alst = new;
	}
}
