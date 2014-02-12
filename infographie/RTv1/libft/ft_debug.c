/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:35:47 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/26 20:32:27 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_change_space(int flag)
{
	static int	i = 0;

	if (flag == 1)
		++i;
	else if (flag == -1)
		--i;
	return (i);
}

void		qw(char *str)
{
	int		i;
	int		j;

	i = ft_change_space(1);
	j = 0;
	ft_putstr_fd("\n** Beg ", 2);
	while (j < i)
	{
		ft_putstr_fd("  ", 2);
		++j;
	}
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" **", 2);
}

void		qs(char *str)
{
	int		j;

	j = ft_change_space(-1) + 1;
	ft_putstr_fd("\n** End ", 2);
	while (j > 0)
	{
		ft_putstr_fd("  ", 2);
		--j;
	}
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" **", 2);
}

void		qe(char *str)
{
	int		j;

	j = ft_change_space(0) + 1;
	ft_putstr_fd("\n** Wrg ", 2);
	while (j > 0)
	{
		ft_putstr_fd("  ", 2);
		--j;
	}
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" **", 2);
}

void		qa(char *str)
{
	ft_putstr_fd("\n-- Str  **", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("**", 2);
}
