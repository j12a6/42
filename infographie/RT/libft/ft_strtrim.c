/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:38:00 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/31 10:16:19 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		++i;
	if (i == (int)ft_strlen(s))
	{
		if (!(str = (char *)gmalloc(sizeof(char) * (1))))
			return (NULL);
		*(str + 0) = '\0';
		return (str);
	}
	j = (int)ft_strlen(s) - 1;
	while (*(s + j) == ' ' || *(s + j) == '\n' || *(s + j) == '\t')
		--j;
	if (!(str = (char *)gmalloc(sizeof(char) * (j - i + 1 + 1))))
		return (NULL);
	str = ft_strsub(s, i, j - i + 1);
	return (str);
}
