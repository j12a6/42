/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 11:07:53 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/29 17:02:32 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_minishell1.h"
#include "libft.h"

void	ft_cd(char *line)
{
	if (chdir((line + 3)) == -1)
		ft_putendl("cd: not a directory");
}
