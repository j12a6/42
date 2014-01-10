/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:37:55 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/28 19:32:06 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
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
			new->next++;
		new->next = *alst;
		*alst = new;
	}
}
