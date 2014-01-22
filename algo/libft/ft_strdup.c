/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:07:15 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 17:14:43 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = (char *)gmalloc(sizeof(*str) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}
