/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:10:23 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/25 15:17:22 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_lst	*ft_lstnew_int(int nombre)
{
	t_lst		*tmp;

	if (!(tmp = (t_lst *)malloc(sizeof(*tmp))))
		exit (-1);
	tmp->nb = nombre;
	tmp->next = NULL;
	return (tmp);
}

t_lst			*ft_create_list(int argc, char **argv)
{
	int			n;
	t_lst		*list;
	t_lst		*first;

	n = 1;
	list = ft_lstnew_int(ft_atoi(argv[n]));
	first = list;
	n++;
	while (n < argc)
	{
		list->next = ft_lstnew_int(ft_atoi(argv[n]));
		list = list->next;
		n++;
	}
	list = first;
	return (list);
}
