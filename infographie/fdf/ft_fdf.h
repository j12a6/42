/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 10:44:36 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 18:56:05 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_FDF_H
# define	FT_FDF_H

# include <string.h>
# include "libft.h"

# define	OGN				500
# define	A				3
# define	C1				10
# define	C2				10
# define	COLOR_UP		0x00FFFF
# define	COLOR_DOWN		0xFFFF55

# ifndef	T_LST
#  define	T_LST

typedef struct			s_lst
{
	char				*line;
	struct s_lst		*next;
}						t_lst;

# endif	/* !T_LST */

# ifndef	T_FDF
#  define	T_FDF

typedef struct			s_fdf
{
	int					**tab;
	int					nb_line;
	int					nb_col;
	void				*mlx_ptr;
	void				*win;
}						t_fdf;

# endif	/* !T_FDF */

# ifndef	T_COORD
#  define	T_COORD

typedef struct			s_coord
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
}						t_coord;

# endif	/* !T_COORD */

int			**ft_create_tab(t_lst *list, int nb_line, int nb_col);
int			key_hook(int keycode, t_fdf *e);
int			expose_hook(t_fdf *e);
void		ft_draw_grid(int **tab, int nb_line, int nb_col);

#endif	/* !FT_FDF_H */
