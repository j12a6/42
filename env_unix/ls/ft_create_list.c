/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 20:21:16 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/15 20:40:20 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls		*ft_ls_lstnew(char *dir_name, time_t time)
{
	t_ls		*list;

	list = (t_ls *)malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	list->name = dir_name;
	list->time = time;
	list->next = NULL;
	return (list);
}

t_ls		*ft_create_list_a(char *dir)
{
	t_ls			*first_elem;
	t_ls			*list;
	DIR				*dirp;
	struct dirent	*read;
	struct stat		*p_stat;

	p_stat = (struct stat *)malloc(sizeof(*p_stat));
	dirp = opendir(dir);
	if ((read = readdir(dirp)))
	{
		lstat(read->d_name, p_stat);
		if (!(list = ft_ls_lstnew(read->d_name, p_stat->st_mtime)))
			return (NULL);
		first_elem = list;
	}
	while ((read = readdir(dirp)))
	{
		if (lstat(read->d_name, p_stat) == -1)
			return (NULL);
		if (!(list->next = ft_ls_lstnew(read->d_name, p_stat->st_mtime)))
			return (NULL);
		list = list->next;
	}
	closedir(dirp);
	return (first_elem);
}

t_ls		*ft_create_list(char *dir)
{
	t_ls			*first_elem;
	t_ls			*list;
	DIR				*dirp;
	struct dirent	*read;
	struct stat		*p_stat;

	p_stat = (struct stat *)malloc(sizeof(*p_stat));
	dirp = opendir(dir);
	while ((read = readdir(dirp)) && read->d_name[0] == '.')
		;
	lstat(read->d_name, p_stat);
	list = ft_ls_lstnew(read->d_name, p_stat->st_mtime);
	first_elem = list;
	while ((read = readdir(dirp)))
	{
		lstat(read->d_name, p_stat);
		if (read->d_name[0] != '.')
		{
			if (!(list->next = ft_ls_lstnew(read->d_name, p_stat->st_mtime)))
				return (NULL);
			list = list->next;
		}
	}
	closedir(dirp);
	return (first_elem);
}
