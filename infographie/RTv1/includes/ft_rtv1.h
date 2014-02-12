/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtv1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 16:07:28 by jaubert           #+#    #+#             */
/*   Updated: 2014/02/12 20:25:58 by jaubert          ###   ########.fr       */
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
/*# define	CAM_X	0
# define	CAM_Y	0
# define	CAM_Z	0*/

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
}					t_mlx;

typedef struct		s_v
{
	double			x;
	double			y;
	double			z;
}					t_v;

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
}					t_sph;

int		ft_raytracing(t_mlx *mlx);
void	ft_put_pixel_in_image(t_img *img, int i, int j);

#endif /* !FT_RTV1_H */
