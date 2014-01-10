/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:55:59 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/29 21:22:46 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_minishell1.h"
#include "libft.h"

char	**ft_setenv(char *line, char **env)
{
	int		i;
	int		j;
	int		n;
	char	**tab;

	i = 0;
	j = 0;
	n = 0;
	tab = ft_cpy_char2(env);
	while (tab[i])
		i++;
	tab[i] = (char *)malloc(sizeof(*tab[i]) * ft_strlen(line + 7) * 100);
	tab[i] = ft_strcpy(tab[i], line + 7);
	while (tab[i][j])
	{
		if (tab[i][j] == '=')
			n++;
		j++;
	}
	if (n != 1)
		ft_putendl("please enter couple NAME=VALUE");
	return (tab);
}
