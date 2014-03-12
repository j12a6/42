/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:33:09 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/12 12:33:14 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin2.h"
#include "libft.h"

void		ft_putlink(t_link *hist)
{
	while (hist->prev)
		hist = hist->prev;
	while (hist)
	{
		ft_putendl(hist->name);
		hist = hist->next;
	}
	ft_putchar('\n');
}

void		ft_print_path(t_game *game, t_link *path, t_link *hist)
{
	int			ant;
	t_link		*beg;

	ft_putlink(hist);
	ft_find_little_path(game, &path);
	beg = path;
	ant = 1;
	while (ant <= game->nb_ant)
	{
		path = beg;
		while (path)
		{
			ft_putchar('L');
			ft_putnbr(ant);
			ft_putchar('-');
			ft_putstr(path->name);
			ft_putchar('\n');
			path = path->next;
		}
		++ant;
	}
}
