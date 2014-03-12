/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:07:28 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/16 15:05:14 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_RTV1_H
# define	FT_RTV1_H

# define	W_W			640.0
# define	W_H			480.0
# define	R			0.66
# define	L			-0.66
# define	T			0.5
# define	B			-0.5
# define	PRJ_X(i)	(L + (R - L) * i / W_W)
# define	PRJ_Y(j)	(T - (T - B) * j / W_H)
# define	CAM_X		0
# define	CAM_Y		2
# define	CAM_Z		10

typedef struct		s_clr
{
	int				r;
	int				g;
	int				b;
}					t_clr;

typedef struct		s_img
{
	char			*data;
	int				bpp;
	int				sl;
	int				endian;
}					t_img;

typedef struct		s_v
{
	double			x;
	double			y;
	double			z;
}					t_v;

typedef struct		s_base
{
	t_v				v1;
	t_v				v2;
	t_v				v3;
}					t_base;

typedef struct		s_cam
{
	t_v				e;
	t_v				d;
	double			sol;
}					t_cam;

typedef struct		s_sph
{
	t_v				c;
	double			r;
	double			ind;
	t_clr			clr;
}					t_sph;

typedef struct		s_sl
{
	t_sph			sph;
	struct s_sl		*next;
}					t_sl;

typedef struct		s_plan
{
	t_v				p;
	t_v				n;
	double			ind;
	t_clr			clr;
}					t_plan;

typedef struct		s_pl
{
	t_plan			plan;
	struct s_pl		*next;
}					t_pl;

typedef struct		s_cyl
{
	t_v				c;
	t_v				a;
	double			r;
	double			ind;
	t_clr			clr;
	double			**mat;
	t_base			b;
	t_v				c2;
	t_v				e2;
	t_v				ce;
}					t_cyl;

typedef struct		s_cyll
{
	t_cyl			cyl;
	struct s_cyll	*next;
}					t_cyll;

typedef struct		s_light
{
	t_v				c;
	double			r;
}					t_light;

typedef struct		s_ll
{
	t_light			light;
	struct s_ll		*next;
}					t_ll;

typedef struct		s_obj
{
	t_ll			*ll;
	t_sl			*sl;
	t_pl			*pl;
	t_cyll			*cyll;
}					t_obj;

typedef struct		s_sol
{
	char			c;
	int				ind;
}					t_sol;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_img			i;
	t_obj			obj;
}					t_mlx;

int			ft_raytracing(t_mlx *mlx);
void		ft_put_pixel_in_image(t_mlx *mlx, int i, int j, t_sol sol);
double		ft_nearest_solution(double a, double b, double c);
t_v			ft_diff_vect(t_v vect1, t_v vect2);
t_v			ft_cross_product(t_v vect1, t_v vect2);
double		ft_dot_product(t_v vect1, t_v vect2);
int			ft_save_scene(t_obj *obj, char *file);
void		ft_find_nearest_object(t_sol *sol, t_mlx *mlx, t_cam cam);
void		ft_init_vect(t_v *vect, double x, double y, double z);
double		ft_atod(const char *str);
void		ft_find_nearest_object(t_sol *sol, t_mlx *mlx, t_cam cam);
double		ft_find_nearest_sphere(int *ind, t_cam cam, t_sl *sl);
double		ft_find_nearest_plane(int *ind, t_cam cam, t_pl *pl);
double		ft_find_nearest_cylinder(int *ind, t_cam cam, t_cyll *cll);
int			ft_save_light_in_list(t_ll **ll, int fd);
int			ft_save_sphere_in_list(t_sl **sl, int fd);
int			ft_save_cylinder_in_list(t_cam cam, t_cyll **cyll, int fd);
int			ft_save_plane_in_list(t_pl **pl, int fd);
double		ft_vect_norm(t_v vect);
void		ft_save_transfer_matrix_inverse(double ***mat, t_base *b, t_v w);
void		ft_save_transfer_matrix(double ***mat, t_base *b, t_v w);
void		ft_create_orthonormal_basis(t_v *u, t_v *v, t_v *w);
t_v			ft_transform_in_new_basis(t_v old, double **mat);

#endif /* !FT_RTV1_H */
