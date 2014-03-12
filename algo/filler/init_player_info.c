/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 09:55:24 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/18 11:44:28 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_filler.h"
#include "libft.h"

static void		ft_init_symbols(t_s *s, char c1, char c2)
{
	s->mef = c1;
	s->mel = c1 + 32;
	s->opf = c2;
	s->opl = c2 + 32;
}

void			ft_init_player_info(t_s *s)
{
	char	*line;
	char	**tmp;

	get_next_line(0, &line);
	tmp = ft_strsplit(line, ' ');
	if (!ft_strcmp(tmp[2], "p1"))
		ft_init_symbols(s, 'O', 'X');
	else if (!ft_strcmp(tmp[2], "p2"))
		ft_init_symbols(s, 'X', 'O');
	else
		ft_putendl_fd("Wrong player info line", 2);
	free((void *)line);
	ft_free_chtab(tmp);
}
