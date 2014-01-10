/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:05:14 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/10 10:13:23 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int			main(int argc, char **argv)
{
	int			n;
	t_push		*list;
	t_min		*min;

	if (argc < 2)
	{
		ft_putendl("Error");
		return (-1);
	}
	if (!(list = (t_push *)malloc(sizeof(*list)))
		|| !(min = (t_min *)malloc(sizeof(*min))))
		return (-1);
	list->a = ft_create_list(argc, argv);
	list->b = NULL;
	n = ft_count_elem(list->a);
	if (n == 0 || n == 1 || (n == 2 && ft_sort1(list->a) == 1))
		return (0);
	else if (n == 2 && ft_sort1(list->a) == -1)
	{
		ft_swap_s(list->a);
		ft_putstr("sa\n");
	}
	else
		list = ft_a_to_b(list, min);
	return (0);
}
