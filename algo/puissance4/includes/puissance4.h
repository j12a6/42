/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 11:57:18 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/09 21:33:30 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# define	BUF_SIZE	4
# define	ME_4_1		5000
# define	YOU_4_1		4000
# define	ME_4_2		3000
# define	YOU_4_2		2000

typedef struct		s_s
{
	int				*choices;
	int				*save;
	char			symb1;
	char			symb2;
	int				keep;
}					t_s;

typedef struct		s_all
{
	char			**grid;
	int				li;
	int				co;
	int				i;
	int				j;
}					t_all;

typedef struct		s_bound
{
	int				start_li;
	int				start_co;
	int				end_li;
	int				end_co;
}					t_bound;

int			ft_play_the_game(t_all *a, t_s *me, t_s *you);
void		ft_print_grid(t_all a);
int			ft_find_nb_for_row(t_all a, t_s s);
int			ft_find_nb_for_column(t_all a, t_s s);
int			ft_find_nb_for_diag_up_left(t_all a, t_s s);
int			ft_find_nb_for_diag_up_right(t_all a, t_s s);
int			ft_update_grid_of_choices(t_all a, t_s *me, t_s *you);
void		ft_reset_save_board(int **save);
int			ft_won(t_all a, t_s *me, t_s *you);

#endif	/* PUISSANCE4_H */
