/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 16:36:47 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/13 19:15:15 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_total(t_ls *list, struct stat *p_stat)
{
	blkcnt_t		block_size;

	block_size = 0;
	ft_putstr("total ");
	while (list != NULL)
	{
		if (lstat(list->name, p_stat) == -1)
			return (-1);
		block_size += p_stat->st_blocks;
		list = list->next;
	}
	return (block_size);
}

static void		ft_print_rights(struct stat *p_stat)
{
	char	c;

	ft_putchar(c = (S_IRUSR & p_stat->st_mode ? 'r' : '-'));
	ft_putchar(c = (S_IWUSR & p_stat->st_mode ? 'w' : '-'));
	if (S_ISUID & p_stat->st_mode)
		ft_putchar(c = (S_IXUSR & p_stat->st_mode ? 's' : 'S'));
	else
		ft_putchar(c = (S_IXUSR & p_stat->st_mode ? 'x' : '-'));
	ft_putchar(c = (S_IRGRP & p_stat->st_mode ? 'r' : '-'));
	ft_putchar(c = (S_IWGRP & p_stat->st_mode ? 'w' : '-'));
	if (S_ISGID & p_stat->st_mode)
		ft_putchar(c = (S_IXGRP & p_stat->st_mode ? 's' : 'S'));
	else
		ft_putchar(c = (S_IXGRP & p_stat->st_mode ? 'x' : '-'));
	ft_putchar(c = (S_IROTH & p_stat->st_mode ? 'r' : '-'));
	ft_putchar(c = (S_IWOTH & p_stat->st_mode ? 'w' : '-'));
	if (S_ISVTX & p_stat->st_mode)
		ft_putchar(c = (S_IXOTH & p_stat->st_mode ? 't' : 'T'));
	else
		ft_putchar(c = (S_IXOTH & p_stat->st_mode ? 'x' : '-'));
}

static void		ft_print_mode(struct stat *p_stat)
{
	if (S_IFMT & S_IFIFO & p_stat->st_mode)
		ft_putchar('p');
	else if (S_IFCHR & p_stat->st_mode)
		ft_putchar('c');
	else if (S_IFDIR & p_stat->st_mode)
		ft_putchar('d');
	else if (S_IFBLK & p_stat->st_mode)
		ft_putchar('b');
	else if (S_IFREG & p_stat->st_mode)
		ft_putchar('-');
	else if (S_IFLNK & p_stat->st_mode)
		ft_putchar('l');
	else if (S_IFSOCK & p_stat->st_mode)
		ft_putchar('s');
	ft_print_rights(p_stat);
}

static int		ft_ls_l_print_info(struct stat *p_stat)
{
	struct passwd	*p_pwd;
	struct group	*p_group;

	if (!(p_pwd = (struct passwd *)malloc(sizeof(*p_pwd))))
		return (-1);
	if (!(p_group = (struct group *)malloc(sizeof(*p_group))))
		return (-1);
	p_pwd = getpwuid(p_stat->st_uid);
	p_group = getgrgid(p_stat->st_gid);
	ft_print_mode(p_stat);
	ft_putstr("  ");
	ft_putnbr(p_stat->st_nlink);
	ft_putchar('\t');
	ft_putstr(p_pwd->pw_name);
	ft_putstr("  ");
	ft_putstr(p_group->gr_name);
	ft_putstr("  ");
	ft_putnbr(p_stat->st_size);
	ft_putstr("\t");
	ft_putstr(ft_strsub(ctime(&p_stat->st_mtime), 4, 12));
	ft_putstr(" ");
	return (1);
}

int				ft_ls_l(t_ls *list)
{
	struct stat		*p_stat;

	if (!(p_stat = (struct stat *)malloc(sizeof(*p_stat))))
		return (-1);
	ft_putnbr(ft_total(list, p_stat));
	ft_putchar('\n');
	while (list != NULL)
	{
		if (lstat(list->name, p_stat) == -1)
			return (-1);
		if (ft_ls_l_print_info(p_stat) == -1)
			return (-1);
		ft_putendl(list->name);
		list = list->next;
	}
	return (1);
}
