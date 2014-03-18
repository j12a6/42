/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:43:47 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/18 21:36:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RT_H
# define	RT_H

# define	HEIGHT		(920)
# define	WIDTH		(1080)
# define	MIN			(-1000000000)
# define	MAX			(1000000000)
# define	E6			(0.000001)
# define	NB_TYPE		4

typedef struct		s_v
{
	double			x;
	double			y;
	double			z;
}					t_v;

typedef struct		s_b
{
	t_v				vx;
	t_v				vy;
	t_v				vz;
}					t_b;

typedef struct		s_r
{
	t_v				o_w;
	t_v				d_w;
	double			t0;
	double			t1;
}					t_r;

typedef struct		s_box
{
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			zmin;
	double			zmax;
}					t_box;

typedef struct		s_sph
{
	t_v				c;
	double			r;
}					t_sph;

typedef struct		s_pla
{
	t_v				c;
	t_v				n;
}					t_pla;

typedef struct		s_dis
{
	t_v				c;
	t_v				n;
	double			r;
}					t_dis;

typedef struct		s_save
{
	int				i;
	int				j;
}					t_save;

typedef struct		s_cam
{
	t_b				b;
	t_v				trans;
	t_v				ro;
	t_v				rp;
}					t_cam;

typedef struct		s_obj
{
	void			**type[NB_TYPE];
	int				nb[NB_TYPE];
	int				(*fct[NB_TYPE])(t_r *, void *);
}					t_obj;

/* Vectors */
void		ft_init_vect(t_v *vect, double x, double y, double z);
void		ft_vect_difference(t_v *vect, t_v vect1, t_v vect2);
double		ft_dot_product(t_v vect1, t_v vect2);
void		ft_multiply_vect_by_scalar(t_v *vext, double scalar, t_v v1);
void		ft_normalize_vect(t_v *vect);
double		ft_vect_norm(t_v vect);

/* Matrices */
double		**ft_init_matrix(t_v v1, t_v v2, t_v v3, t_v trans);
void		ft_multiply_vect_and_matrix(t_v *v, double **mat, t_v v1);

/* Camera */
int			ft_find_pixel_pos_on_screen(t_v *rp_c, int i, int j);

/* Others */
int			ft_error(char *s1, char *s2, int val);

#endif	/* !RT_H */
