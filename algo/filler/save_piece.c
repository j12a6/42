/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 09:13:05 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/18 11:56:28 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_filler.h"
#include "libft.h"

int		ft_save_new_piece(char *line, t_p *p)
{
	int		i;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	p->li = ft_atoi(tmp[1]);
	p->co = ft_atoi(tmp[2]);
	if (!(p->fig = (char **)malloc(sizeof(char *) * (p->li))))
		return (-1);
	free((void *)line);
	i = 0;
	while (i < p->li && get_next_line(0, &line))
	{
		p->fig[i] = ft_strdup(line);
		free((void *)line);
		++i;
	}
	return (0);
}
