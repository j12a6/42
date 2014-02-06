/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:26:49 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/26 21:03:26 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_minishell2.h"
#include "libft.h"

void	ft_pwd(char **all)
{
	char	*buf;
	char	*str;

	if (!(buf = (char *)gmalloc(sizeof(char) * 2048 + 1)))
	{
		ft_putendl_fd("pwd: malloc error", 2);
		return ;
	}
	if (all[1])
		ft_putendl("cd: too many arguments");
	else
	{
		if (!(str = getcwd(buf, 2048)))
		{
			gofree((void *)buf);
			return ;
		}
		ft_putendl(str);
		gofree((void *)str);
		gofree((void *)buf);
	}
}
