/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 15:29:57 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:22 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "sh.h"

void		ft_echo(t_p *p)
{
	t_p		*move;
	int		space;
	int		back_to_line;

	space = 0;
	back_to_line = 0;
	move = p->next;
	if (move)
	{
		while (move && !ft_strcmp(move->tok, "-n"))
		{
			++back_to_line;
			move = move->next;
		}
	}
	while (move)
	{
		if (space)
			write(1, " ", 1);
		ft_putstr(move->tok);
		++space;
		move = move->next;
	}
	if (!back_to_line)
		write(1, "\n", 1);
}
