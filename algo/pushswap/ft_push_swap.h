/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 12:11:36 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/27 20:18:22 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PUSH_SWAP_H
# define	FT_PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

# ifndef	T_LST
#  define	T_LST

typedef struct			s_lst
{
	int					nb;
	struct s_lst		*next;
}						t_lst;

# endif	/* !T_LST */

# ifndef	T_PUSH
#  define	T_PUSH

typedef struct			s_push
{
	t_lst				*a;
	t_lst				*b;
}						t_push;

# endif	/* !T_PUSH */

# ifndef	T_MIN
#  define	T_MIN

typedef struct			s_min
{
	int					min;
	int					ind_min;
}						t_min;

# endif	/* !T_MIN */

t_lst		*ft_create_list(int argc, char **argv);
void		ft_print_list_int(t_lst *list);
void		ft_swap_s(t_lst *list);
t_push		*ft_swap_pa(t_push *list);
t_push		*ft_swap_pb(t_push *list);
t_lst		*ft_swap_r(t_lst *list);
t_lst		*ft_swap_rr(t_lst *list);
t_push		*ft_a_to_b(t_push *list, t_min *min);
void		ft_init_min_info(t_lst *list, t_min *min);
t_lst		*ft_last(t_lst *list);
int			ft_sort1(t_lst *list);
int			ft_sort2(t_lst *list);
int         ft_count_elem(t_lst *list);

#endif	/* !FT_PUSH_SWAP_H */
