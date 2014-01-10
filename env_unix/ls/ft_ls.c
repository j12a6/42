/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 16:36:47 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/15 20:35:05 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		after_options(int argc, char **argv)
{
	int		n;

	n = 1;
	while (n < argc)
	{
		if ((argv[n][0] == '-' && argv[n][1] == '-') || argv[n][0] != '-')
			return (n);
		if (argv[n][0] == '-' && argv[n][1] != '-')
			n++;
	}
	return (n);
}

static int		ft_options(int argc, char **argv)
{
	int		opt;
	int		n;

	opt = 0;
	n = 1;
	while (n < argc)
	{
		if ((argv[n][0] == '-' && argv[n][1] == '-') || argv[n][0] != '-')
			return (opt);
		if (argv[n][0] == '-' && argv[n][1] != '-')
		{
			if (ft_in_string(argv[n], 'a') == 1 && (opt & 1) == 0)
				opt += 1;
			if (ft_in_string(argv[n], 'r') == 1 && (opt & 2) == 0)
				opt += 2;
			if (ft_in_string(argv[n], 't') == 1 && (opt & 4) == 0)
				opt += 4;
			if (ft_in_string(argv[n], 'l') == 1 && (opt & 8) == 0)
				opt += 8;
		}
		n++;
	}
	return (opt);
}

static void		ft_do_it(char *dir, int opt)
{
	static int		r;
	t_ls			*list;

	r = 1;
	if (opt & 1)
		list = ft_create_list_a(dir);
	else
		list = ft_create_list(dir);
	if (opt & 2)
		r = -1;
	list = ft_sort(list, r);
	if (opt & 4)
		list = ft_sort_t(list, r);
	if (opt & 8)
		ft_ls_l(list);
	else
		ft_print_list(list);
}

static void		ft_main_2(int argc, char **argv, int opt)
{
	int		n;

	n = after_options(argc, argv);
	if (n == argc)
		ft_do_it(".", opt);
	else if (argc == 2)
		ft_do_it(argv[n], opt);
	else
	{
		while (n < argc)
		{
			ft_putstr(argv[n]);
			ft_putendl(":");
			ft_do_it(argv[n], opt);
			if (n != argc - 1)
				ft_putchar('\n');
			n++;
		}
	}
}

int				main(int argc, char **argv)
{
	int			opt;

	opt = 0;
	if (argc == 1)
		ft_do_it(".", 0);
	else
	{
		opt = ft_options(argc, argv);
		ft_main_2(argc, argv, opt);
	}
	return (0);
}
