/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:07:15 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/01 22:43:35 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (s1 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1)) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, (void *)s1);
	return (str);
}
