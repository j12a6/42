/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 08:25:55 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/21 10:25:59 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_filler.h"
#include "libft.h"

static int		ft_special_symb(t_m *m, t_s *s, int touch)
{
	if (m->all[m->x][m->y] == s->mef || m->all[m->x][m->y] == s->mel)
		++touch;
	else if (m->all[m->x][m->y] == s->opf || m->all[m->x][m->y] == s->opl)
		return (-1);
	return (touch);
}

static int		ft_try_position(t_m *m, t_p *p, t_s *s)
{
	int		i;
	int		j;
	int		touch;

	touch = 0;
	i = 0;
	while (i < p->li && touch <= 1)
	{
		j = 0;
		while (j < p->co && touch <= 1)
		{
			if (p->fig[i][j] == '*')
			{
				m->x = (m->gli + i + m->li) % m->li;
				m->y = (m->gco + j + m->co) % m->co;
				if ((touch = ft_special_symb(m, s, touch)) == -1)
					return (-1);
			}
			++j;
		}
		++i;
	}
	if (touch != 1)
		return (-1);
	return (1);
}

static void		ft_place_my_piece(t_m *m, t_p *p, t_s *s)
{
	m->gli = -p->li;
	while (m->gli < m->li - p->li)
	{
		m->gco = -p->co;
		while (m->gco < m->co - p->co)
		{
			if (ft_try_position(m, p, s) == 1)
				return ;
			++m->gco;
		}
		++m->gli;
	}
}

static int		ft_find_best_position(char *line, t_m *m, t_p *p, t_s *s)
{
	if (ft_save_new_map(line, m) == -1)
		return (-1);
	get_next_line(0, &line);
	if (ft_save_new_piece(line, p) == -1)
		return (-1);
	ft_place_my_piece(m, p, s);
	return (0);
}

int				main(void)
{
	char		*line;
	t_m			*m;
	t_p			*p;
	t_s			*s;

	if (!(m = (t_m *)malloc(sizeof(*m))) || !(p = (t_p *)malloc(sizeof(*p)))
		|| !(s = (t_s *)malloc(sizeof(*s))))
		return (-1);
	ft_init_player_info(s);
	while (get_next_line(0, &line) && line[0] != '=')
	{
		if (ft_find_best_position(line, m, p, s) == -1)
			return (-1);
		ft_putnbr(m->gli);
		ft_putstr(" ");
		ft_putnbr(m->gco);
		ft_putchar('\n');
	}
	return (0);
}
