/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 10:39:51 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 19:06:52 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "ft_fdf.h"

static int		ft_count_elem(t_lst *list)
{
	int			i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

static int		ft_size(t_lst *list)
{
	int		n;

	n = 0;
	while (list)
	{
		if (ft_count_wd(list->line, ' ') > n)
			n = ft_count_wd(list->line, ' ');
		list = list->next;
	}
	return (n);
}

static t_lst	*ft_lstnew_fdf(char *str)
{
	t_lst		*list;

	if (!(list = (t_lst *)malloc(sizeof(*list)))
		|| !(list->line = ft_strnew(ft_strlen(str))))
		exit(-1);
	ft_strcpy(list->line, str);
	list->next = NULL;
	return (list);
}

static t_lst	*ft_create_list(char **argv)
{
	int			fd;
	char		*line;
	t_lst		*list;
	t_lst		*first;

	if (!(list = (t_lst *)malloc(sizeof(t_fdf))))
		exit(-1);
	if ((fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR)) == -1)
		exit(-1);
	if (get_next_line(fd, &line))
	{
		list = ft_lstnew_fdf(line);
		first = list;
	}
	while (get_next_line(fd, &line))
	{
		list->next = ft_lstnew_fdf(line);
		list = list->next;
	}
	list = first;
	return (list);
}

int				main(int argc, char **argv)
{
	int			nb_line;
	int			nb_col;
	t_lst		*list;
	int			**tab;

	if (argc != 2)
		return (-1);
	list = ft_create_list(argv);
	nb_col = ft_size(list);
	nb_line = ft_count_elem(list);
	tab = ft_create_tab(list, nb_line, nb_col);
	ft_draw_grid(tab, nb_line, nb_col);
	return (0);
}
