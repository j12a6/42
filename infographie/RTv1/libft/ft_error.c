/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 10:29:31 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 14:07:20 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_error(char *error, char *str)
{
	if (ft_strcmp(error, "malloc") == 0)
		ft_putstr_fd("Problem malloc: ", 2);
	else if (ft_strcmp(error, "open") == 0)
		ft_putstr_fd("Problem open: ", 2);
	else if (ft_strcmp(error, "map empty") == 0)
		ft_putstr_fd("Map empty: ", 2);
	else if (ft_strcmp(error, "env") == 0)
		ft_putstr_fd("Env empty: ", 2);
	else if (ft_strcmp(error, "ac") == 0)
		ft_putstr_fd("Wrong number of argument: ", 2);
	ft_putendl_fd(str, 2);
	cfree();
}
