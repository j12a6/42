/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gclean.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 16:07:27 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 17:24:37 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	gclean(t_list **list)
{
	t_list	*first;
	t_list	*tmp;

	first = *list;
	while (first)
	{
		tmp = first;
		free(first->content);
		first = first->next;
		free((void *)tmp);
	}
	*list = NULL;
}
