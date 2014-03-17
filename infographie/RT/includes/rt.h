/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:43:47 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/17 20:23:02 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RT_H
# define	RT_H

# define	HEIGHT		920
# define	WIDTH		1080
# define	INT_MIN		-2147483648
# define	INT_MAX		2147483647

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
	t_v				o;
	t_v				d;
	double			tmin;
	double			tmax;
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

/* Vectors */
void		ft_init_vect(t_v *vect, double x, double y, double z);
void		ft_vect_difference(t_v *vect, t_v vect1, t_v vect2);
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
