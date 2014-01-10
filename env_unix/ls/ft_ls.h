/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 16:51:59 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/15 20:36:05 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_LS_H
# define	FT_LS_H

#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

typedef struct			s_ls
{
	char				*name;
	time_t				time;
	struct s_ls			*next;
}						t_ls;

int			ft_in_string(char *str, char c);
t_ls		*ft_ls_lstnew(char *dir_name, time_t time);
int			ft_lstlen(t_ls *list);
void		ft_print_list(t_ls *list);
t_ls		*ft_create_list_a(char *dir);
t_ls		*ft_create_list(char *dir);
t_ls		*ft_sort_t(t_ls *list, int r);
t_ls		*ft_sort(t_ls *list, int r);
int			ft_ls_l(t_ls *list);

#endif		/* !FT_LS_H */
