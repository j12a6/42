/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:45:34 by jaubert           #+#    #+#             */
/*   Updated: 2013/11/27 18:44:20 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = 0;
	while (*(s2 + length))
		length++;
	if (*(s2 + j) == '\0')
		return ((void *)(s1 + j));
	while (*(s1 + i))
	{
		while (*(s1 + i) == *(s2 + j))
		{
			i++;
			j++;
			if (j == length)
				return ((void *)(s1 + i - j));
		}
		i = i - j + 1;
		j = 0;
	}
	return ('\0');
}
