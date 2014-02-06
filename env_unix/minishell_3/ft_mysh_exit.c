/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mysh_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 16:27:18 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/26 21:02:58 by jaubert          ###   ########.fr       */
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


static int		ft_mysh_exit_2(char **all)
{
	int		exit;

	exit = -1;
	if (!all[1])
	{
		exit = 0;
		goclean();
	}
	else if (all[1] && all[2])
		ft_putendl("exit: too many arguments");
	else if (all[1] && !ft_is_numeric(all[1]))
	{
		exit = ft_atoi(all[1]);
		goclean();
	}
	else
		ft_putendl("exit: enter a numeric argument between 0 and 999999999");
	return (exit % 256);
}

int				ft_mysh_exit(char *line)
{
	int		exit;
	char	**all;

	if (!(all = ft_strparse(line)))
		return (-2);
	exit = -1;
	if (all[0] && !ft_strcmp(all[0], "exit"))
		exit = ft_mysh_exit_2(all);
	return (exit);
}
