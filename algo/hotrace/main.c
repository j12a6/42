/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 13:26:37 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/15 17:03:30 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "librace.h"

static t_race	*ft_lst_race(char *key, char *val)
{
	t_race		*new;
	char		*tmp;

	if (!(new = (t_race *)malloc(sizeof(*new)))
	|| !(new->key = ft_strnew(ft_strlen(key) + 1))
	|| !(new->val = ft_strnew(ft_strlen(val) + 1))
	|| !(tmp = ft_strnew(ft_strlen(key) + 1)))
		return (NULL);
	ft_bzero(new, sizeof(*new));
	tmp = (!key) ? NULL : ft_strcpy(tmp, key);
	new->key = tmp;
	if (!(tmp = ft_strnew(ft_strlen(val) + 1)))
		return (NULL);
	tmp = (!val) ? NULL : ft_strcpy(tmp, val);
	new->val = tmp;
	new->next = NULL;
	return (new);
}

static void		ft_search(char *word, t_race *list)
{
	t_race		*tmp;

	tmp = list;
	while (list)
	{
		if (ft_strcmp(list->key, word) == 0)
		{
			ft_putendl(list->val);
			list = tmp;
			return ;
		}
		list = list->next;
	}
	list = tmp;
	ft_putstr(word);
	ft_putstr(": ");
	ft_putendl("Not found.");
}

static int		ft_compare(t_race *list, char *str1, char *str2)
{
	t_race		*tmp;

	tmp = list;
	while (list)
	{
		if (ft_strcmp(list->key, str1) == 0)
		{
			if (!(list->val = ft_strnew(ft_strlen(str2) + 1)))
				return (0);
			ft_strcpy(list->val, str2);
			list = tmp;
			return (0);
		}
		list = list->next;
	}
	list = tmp;
	return (-1);
}

static void		ft_do_list(char *line, t_race *list, char *str1, char *str2)
{
	t_race		*tmp;

	tmp = list;
	free((void *)line);
	free((void *)str1);
	free((void *)str2);
	while (get_next_line(0, &line) > 0 && *(line) != '\0')
	{
		str1 = ft_strdup(line);
		free((void *)line);
		if (get_next_line(0, &line) > 0)
		{
			str2 = ft_strdup(line);
			free((void *)line);
			if (ft_compare(tmp, str1, str2) == -1)
			{
				list->next = ft_lst_race(str1, str2);
				list = list->next;
			}
		}
		free((void *)str1);
		free((void *)str2);
	}
	while (get_next_line(0, &line) > 0)
		ft_search(line, tmp);
}

int				main(void)
{
	char		*line;
	t_race		*list;
	char		*str1;
	char		*str2;
	t_race		*tmp;

	if (!(str1 = ft_strnew(2)) || !(str2 = ft_strnew(2)))
		return (0);
	if (get_next_line(0, &line) > 0)
		str1 = ft_strdup(line);
	free((void *)line);
	if (get_next_line(0, &line) > 0)
		str2 = ft_strdup(line);
	list = ft_lst_race(str1, str2);
	tmp = list;
	ft_do_list(line, list, str1, str2);
	while ((list = tmp))
	{
		tmp = tmp->next;
		list->key = NULL;
		list->val = NULL;
		list->next = NULL;
		free((void *)list);
	}
	return (0);
}
