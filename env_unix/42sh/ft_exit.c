/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:15:32 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:08:16 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "sh.h"

static int		ft_verif_num_exit(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		++i;
	while (num[i])
	{
		if (!(ft_isdigit((int)num[i])))
			return (-1);
		++i;
	}
	return (0);
}

int				ft_exit(t_p *p)
{
	int		status;

	status = 0;
	if (!p->next)
	{
		ft_putendl("exit");
		exit(status);
	}
	else if (p->next->next
			|| ((ft_verif_num_exit(p->next->tok)) == -1))
		return (ft_error_msg("exit: Expression Syntax", ""));
	else
	{
		status = ft_atoi(p->next->tok) % 256;
		ft_putendl("exit");
		exit(status);
	}
	return (0);
}
