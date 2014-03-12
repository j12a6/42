/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 08:11:39 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/18 11:56:30 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_filler.h"
#include "libft.h"

int		ft_save_new_map(char *line, t_m *m)
{
	int		i;
	char	**map_info;

	map_info = ft_strsplit(line, ' ');
	map_info[2] = ft_strsub(map_info[2], 0, ft_strlen(map_info[2]) - 1);
	m->li = ft_atoi(map_info[1]);
	m->co = ft_atoi(map_info[2]);
	ft_free_chtab(map_info);
	free((void *)line);
	get_next_line(0, &line);
	free((void *)line);
	if (!(m->all = (char **)malloc(sizeof(char *) * (m->li))))
		return (-1);
	i = 0;
	while (i < m->li && get_next_line(0, &line))
	{
		m->all[i] = ft_strdup(line + 4);
		free((void *)line);
		++i;
	}
	return (0);
}
