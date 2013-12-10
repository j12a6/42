/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:19:35 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/10 19:51:40 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*i;
	t_list		*temp;

	if (*alst == NULL)
		return ;
	i = *alst;
	temp = i;
	while (i != NULL)
	{
		del(i->content, i->content_size);
		free(i);
		temp = temp->next;
		i = temp;
	}
	*alst = NULL;
}
