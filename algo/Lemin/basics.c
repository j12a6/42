/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:32:59 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/12 12:34:32 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin2.h"

int			is_comment(char *line)
{
	if (line == NULL || *line == '\0')
		return (0);
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int			is_number(char *line)
{
	if (*line == '-')
		line++;
	while (*line)
	{
		if (!(ft_isdigit(*line)))
			return (0);
		line++;
	}
	return (1);
}

int			where_is_c_in_str(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int			how_much_c_in_str(char c, char *str)
{
	int			i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

char		*ft_get_name(char *line, char c, int i)
{
	char		*ret;
	int			k;
	int			j;

	if (line == NULL)
		return (NULL);
	k = 0;
	while (k < i)
	{
		if (*line == c)
			k++;
		line++;
	}
	k = 0;
	while (line[k] && line[k] != c)
		k++;
	if (k == 0)
		return (NULL);
	if (!(ret = (char *)gmalloc(sizeof(char) * (k + 1))))
		return (NULL);
	j = -1;
	while (++j < k)
		ret[j] = line[j];
	ret[j] = '\0';
	return (ret);
}
