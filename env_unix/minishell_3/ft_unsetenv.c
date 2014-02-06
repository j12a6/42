/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 18:53:39 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/26 21:06:34 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_unsetenv(char **all, char **env)
{
	if (!all[1])
		ft_putendl("unsetenv: too few arguments");
	else if (all[2])
		ft_putendl("unsetenv: too many arguments");
	else
		ft_putendl("unsetenv: better not deleting that");
	return (env);
}
