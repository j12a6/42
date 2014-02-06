/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:26:49 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/01 12:10:59 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include "libft.h"

int				main(int ac, char **av, char **env)
{
	int		i;
	char	*line;
	char	**all;
	char	**e_cp;
	int		exit;

	if (ac != 1 || !av[0] || !(e_cp = ft_ts_copy(env)) || !ft_putstr("_$> "))
		return (-1);
	while (get_next_line(0, &line) != 0)
	{
		all = ft_strsplit(line, ';');
		i = -1;
		while (all[++i])
		{
			all[i] = ft_strtrim(all[i]);
			if (all[i][0] && (exit = ft_mysh_exit(all[i])) != -1)
				return (exit);
			if (all[i][0] && !(e_cp = ft_run_big_part(all[i], e_cp)))
				break ;
		}
		ft_putstr("_$> ");
	}
	goclean();
	return (0);
}
