/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:15:39 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 14:03:19 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_verification(char const *s, int i)
{
	while (*(s + i))
	{
		if (*(s + i) != ' ' && *(s + i) != '\n' && *(s + i) != '\t')
			return (0);
		i++;
	}
	return (1);
}

static char		*ft_strtrim_next(char const *s, char *trim, int i)
{
	int		j;

	j = 0;
	while (*(s + i))
	{
		if (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		{
			if (ft_verification(s, i))
			{
				*(trim + j) = '\0';
				return (trim);
			}
		}
		*(trim + j++) = *(s + i++);
	}
	*(trim + j) = '\0';
	return (trim);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*trim;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(trim = (char *)gmalloc(sizeof(*trim) * (ft_strlen(s) + 1))))
		return (NULL);
	while ((*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
	&& *(s + i))
		i++;
	return (ft_strtrim_next(s, trim, i));
}
