/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_call.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 11:34:40 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/02 12:36:01 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*c_calls(char *str, char *s1)
{
	void		*s2;

	if (!ft_strcmp(str, "trim"))
		s2 = ft_strtrim(s1);
	else if (!(ft_strcmp(str, "dup")))
		s2 = ft_strdup(s1);
	else if (!(ft_strcmp(str, "plim")))
		s2 = ft_strsplim(s1);
	gfree(s1);
	return (s2);
}

void	*c_calld(char *str, char *s1, char *s2)
{
	void		*s3;

	if (!(ft_strcmp(str, "join")))
		s3 = ft_strjoin(s1, s2);
	gfree(s1);
	gfree(s2);
	return (s3);
}
