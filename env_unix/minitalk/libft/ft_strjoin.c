/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:54:56 by makoudad          #+#    #+#             */
/*   Updated: 2014/01/23 12:58:38 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if (!(s3 = (char *)gmalloc(sizeof(*s3) * (ft_strlen(s1)
											+ ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	return (s3);
}
