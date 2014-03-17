/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ts_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 10:25:15 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/01 12:05:00 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ts_to_str(char **ts)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	len = ft_ts_len_all(ts) + ft_ts_len(ts) - 1;
	if (!(str = (char *)gmalloc(sizeof(char) * (len + 1))))
		return (NULL);
	*(str + len) = '\0';
	--len;
	i = ft_ts_len(ts) - 1;
	while (len > 0)
	{
		j = (int)ft_strlen(ts[i]) - 1;
		while (ts[i][j])
		{
			*(str + len) = ts[i][j];
			--len;
			--j;
		}
		*(str + len) = ' ';
		--len;
		--i;
	}
	return (str);
}
