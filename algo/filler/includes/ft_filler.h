/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 08:11:57 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/18 12:15:44 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

typedef struct		s_p
{
	int				li;
	int				co;
	char			**fig;
}					t_p;

typedef struct		s_m
{
	int				li;
	int				co;
	char			**all;
	int				gli;
	int				gco;
	int				x;
	int				y;
}					t_m;

typedef struct		s_s
{
	char			mef;
	char			mel;
	char			opf;
	char			opl;
}					t_s;

void	ft_init_player_info(t_s *s);
int		ft_save_new_map(char *line, t_m *m);
int		ft_save_new_piece(char *line, t_p *p);

#endif	/* !FT_FILLER_H */
