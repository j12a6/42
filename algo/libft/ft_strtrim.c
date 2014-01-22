/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 18:38:00 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 17:23:57 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s) - 1;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		++i;
	while (*(s + j) == ' ' || *(s + j) == '\n' || *(s + j) == '\t')
		--j;
	if (!(str = (char *)gmalloc(sizeof(*str) * (j - i + 1 + 1))))
		return (NULL);
	s = ft_strsub(s, i, j - i + 1);
	ft_strcpy(str, s);
	return (str);
}
