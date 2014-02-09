/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sh_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:18 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/09 18:15:28 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		if (!ft_isdigit(*(str + i)))
			return (-1);
		++i;
	}
	if (i > 9)
		return (-1);
	return (0);
}

int				ft_my_sh_exit(char *line)
{
	int		exit;
	char	**all;

	exit = -3;
	if (!(all = ft_strparse(line)))
		return (-1);
	if (!all[0])
		return (-2);
	else if (ft_strcmp(all[0], "exit") != 0)
		return (-2);
	else if (!all[1])
		exit = 0;
	else if (all[1] && all[2])
		ft_putendl("exit: too many arguments");
	else if (all[1] && !ft_is_numeric(all[1]))
		exit = ft_atoi(all[1]);
	else
		ft_putendl("exit: enter a numeric argument between 0 and 999999999");
	return (exit % 256);
}
