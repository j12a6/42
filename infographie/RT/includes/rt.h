/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:43:47 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/22 12:25:04 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RT_H
# define	RT_H

# define	HEIGHT			(920.0)
# define	WIDTH			(1280.0)
# define	MAX_DEPTH		0
# define	MIN				(-1000000000.0)
# define	MAX				(1000000000.0)
# define	E6				(0.000001)
# define	E4				(0.0001)
# define	NB_TYPE			4
# define	BOX				0
# define	SPH				1
# define	PLA				2
# define	DIS				3
# define	CYL				4
# define	CON				5

typedef struct		s_v
{
	double			x;
	double			y;
	double			z;
}					t_v;

typedef struct		s_c
{
	int				b;
	int				g;
	int				r;
}					t_c;

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
	t_v				p_hit;
	t_v				n_hit;
	double			t0;
	double			t1;
	double			tnear;
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
	t_c				sf;
	t_c				em;
	double			trsp;
	double			refl;
	double			ior;
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

typedef struct		s_clr
{
	double			fnel;
	t_c				refl;
	t_c				refr;
}					t_clr;

typedef struct		s_cam
{
	t_b				b;
	t_v				trans;
	t_v				ro;
	t_v				rp;
}					t_cam;

typedef struct		s_obj
{
	int				depth;
	t_c				**pixel;
	void			***type;
	int				*nb;
	int				(*intersect[NB_TYPE])(t_r *, void *);
	int				(*treatment[NB_TYPE])(t_r *, void *, t_c *, struct s_obj);
	t_c				bg_clr;
}					t_obj;

typedef struct		s_img
{
	char			*data;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_img			i;
	t_obj			obj;
}					t_mlx;

/* Vectors */
void		ft_init_vect(t_v *vect, double x, double y, double z);
void		ft_vect_opposite(t_v *vect, t_v v1);
void		ft_vect_sum(t_v *vect, t_v v1, t_v v2);
void		ft_vect_difference(t_v *vect, t_v vect1, t_v vect2);
double		ft_dot_product(t_v vect1, t_v vect2);
void		ft_mult_vect_by_nb(t_v *vext, t_v v1, double scalar);
void		ft_normalize_vect(t_v *vect);
double		ft_vect_norm(t_v vect);

/* Matrices */
double		**ft_init_matrix(t_v *v1, t_v *v2, t_v *v3, t_v *trans);
void		ft_mult_vect_by_matrix(t_v *v, double **mat, t_v v1);

/* Colors */

void		ft_mult_color_by_nb(t_c *color, t_c c1, double scalar);
void		ft_init_color(t_c *color, int b, int g, int r);
void		ft_color_sum(t_c *color, t_c color1, t_c color2);
void		ft_mult_color_by_color(t_c *color, t_c color1, t_c color2);

/* Camera */
int			ft_find_pixel_pos_on_screen(t_v *rp_c, int i, int j);
void		ft_init_camera(t_cam *cam);

/* Others */
int			ft_error(char *s1, char *s2, int val);
int			ft_draw(t_mlx *mlx);

int			ft_intersect_a_disk(t_r *r, void *data);
int			ft_intersect_a_box(t_r *r, void *data);
int			ft_intersect_a_sphere(t_r *r, void *data);
int			ft_intersect_a_plane(t_r *r, void *data);

int			ft_treat_a_box(t_r *r, void *data, t_c *color, t_obj obj);
int			ft_treat_a_sphere(t_r *r, void *data, t_c *color, t_obj obj);
int			ft_treat_a_disk(t_r *r, void *data, t_c *color, t_obj obj);
int			ft_treat_a_plane(t_r *r, void *data, t_c *color, t_obj obj);
double		ft_mix(double a, double b, double mix);
int			ft_init_object_structure(t_obj *obj);

int			ft_diffuse_object(t_obj obj, t_r *r, t_c *color, t_c sf);
t_c			ft_trace(t_obj obj, t_r *r, t_save *save);
int			ft_do_scene(t_obj *obj);

#endif	/* !RT_H */
