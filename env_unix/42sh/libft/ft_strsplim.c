/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:17:49 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 13:00:43 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_s_w_m(char const *s, int i)
{
	int		m;

	m = 0;
	while (*(s + i) && *(s + i) != ' ' && *(s + i) != 't')
	{
		++i;
		++m;
	}
	return (m);
}

static int		ft_wc_w_m(char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + i))
	{
		while (*(s + i) && (*(s + i) == ' ' || *(s + i) == '\t'))
			++i;
		if (*(s + i))
			++j;
		while (*(s + i) && *(s + i) != ' ' && *(s + i) != '\t')
			++i;
	}
	return (j);
}

static char		*ft_fill_m(char *s3, int *i, char const *s)
{
	int		j;

	j = 0;
	while (*(s + *i) != ' ' && *(s + *i) != '\t' && *(s + *i))
	{
		s3[j++] = *(s + *i);
		i[0] += 1;
	}
	s3[j] = '\0';
	return (s3);
}

char			**ft_strsplim(char const *s)
{
	char	**s3;
	int		i;
	int		k;

	if (!(s3 = (char **)gmalloc(sizeof(char *) * (ft_wc_w_m(s) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (*(s + i))
	{
		while ((*(s + i) == ' ' || *(s + i) == '\t') && *(s + i))
			++i;
		if (*(s + i))
		{
			if (!(s3[k] = (char *)gmalloc(sizeof(char) * (ft_s_w_m(s, i) + 1))))
				return (NULL);
			s3[k] = ft_fill_m(s3[k], &i, s);
			++k;
		}
	}
	if (!(s3[k] = (char *)gmalloc(sizeof(char) * (1 + 1))))
		return (NULL);
	*(s3 + k) = '\0';
	return (s3);
}
