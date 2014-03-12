/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 10:27:26 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/05 14:17:16 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "sh.h"
#include "libft.h"

static int		ft_find_the_line(t_env e, char *line, t_hl *hlist, t_tree *t)
{
	int		i;
	t_p		*p;

	while (1)
	{
		i = 0;
		p = NULL;
		if ((i = ft_save_line(&hlist, &line, hlist)) == -2)
			return (-1);
		if (i == 0 && line[0] != '\0')
			i = ft_lexical_analyzer(line, &p);
		if (i == 0 && line[0] != '\0')
			i = ft_init_tree(&t);
		if (i == 0 && line[0] != '\0')
			i = ft_p_list_sub(&(t->p), p, NULL);
		if (i == 0 && t && t->p && line[0] != '\0')
			i = ft_syntaxical_analyzer(&t);
		if (i == 0 && line[0] != '\0' && t && t->p)
		{
			ft_execute_all(t, &e);
			ft_free_tree(&t);
		}
		t = NULL;
	}
	return (0);
}

static int		ft_init_basic_env(char ***env)
{
	char	*buf;

	if (!(*env = (char **)gmalloc(sizeof(char *) * 2)))
		return (-1);
	buf = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
	(*env)[0] = ft_strjoin(buf, ":/opt/X11/bin:/usr/texbin");
	gfree(buf);
	buf = NULL;
	buf = getcwd(buf, 0);
	(*env)[1] = ft_strjoin("PWD=", buf);
	free(buf);
	(*env)[2] = NULL;
	return (0);
}

int				main(int ac, char **av, char **env)
{
	t_env				e;
	int					exit;
	struct termios		tattr;

	if (ac != 1 || av == NULL)
		return (-1);
	exit = 0;
	if (!ft_check_signal())
		return (-1);
	if (!(e.envc = ft_copy_ts(env))
		|| !(e.env = ft_copy_ts(env)))
	{
		cfree();
		return (-1);
	}
	if (!(e.env = ft_copy_ts(env)) || (ft_init_basic_env(&(e.env_s)) == -1))
	{
		cfree();
		return (-1);
	}
	if (ft_init_terminal_mode(tattr) != -1)
		exit = ft_find_the_line(e, NULL, NULL, NULL);
	cfree();
	return (exit);
}
