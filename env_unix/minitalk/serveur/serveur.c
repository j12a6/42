/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 08:49:30 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/08 17:59:11 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

char		str_pid[32];
char		str_len[32];
char		*str;
char		one_byte[8];
int			nb_bit;
pid_t		pid;
int			len;

void		ft_bin_to_str(char *one_byte)
{
	int				k;
	int				i;
	int				c;
	static int		j = 0;

	k = 1;
	c = 0;
	i = 8;
	while (--i >= 0)
	{
		if (one_byte[i] == '1')
			c += k;
		k *= 2;
	}
	str[j] = c;
	++j;
	++nb_bit;
	if (nb_bit == len)
	{
		str[j] = '\0';
		ft_putendl(str);
		j = 0;
		gfree((void *)str);
	}
}

int		ft_bin_to_len(char *str_len)
{
	int		k;
	int		i;
	int		c;

	k = 1;
	c = 0;
	i = 32;
	while (--i >= 0)
	{
		if (str_len[i] == '1')
			c += k;
		k *= 2;
	}
	ft_putstr("len = ");
	ft_putnbr(c);
	ft_putchar('\n');
	return (c);
}

void		ft_bin_to_pid(char *str_pid)
{
	int		k;
	int		i;
	int		c;

	k = 1;
	c = 0;
	i = 32;
	while (--i >= 0)
	{
		if (str_pid[i] == '1')
			c += k;
		k *= 2;
	}
	pid = c;
	ft_putstr("pid = ");
	ft_putnbr(pid);
	ft_putchar('\n');
}

void		ft_signal_str(int sign)
{
	static int		i = 7;

	if (sign == SIGUSR1)
	{
		one_byte[i] = '1';
/*		kill(pid, SIGUSR1);*/
/*		kill(pid, SIGUSR2);*/
	}
	else if (sign == SIGUSR2)
	{
		one_byte[i] = '0';
/*		kill(pid, SIGUSR1);*/
/*		kill(pid, SIGUSR2);*/
	}
	--i;
	if (i < 0)
	{
		i = 7;
		ft_bin_to_str(one_byte);
	}
}

void		ft_signal_len(int sign, int *j)
{
	if (*j < 0)
		ft_signal_str(sign);
	else
	{
		if (sign == SIGUSR1)
			str_pid[*j] = '1';
		else if (sign == SIGUSR2)
			str_pid[*j] = '0';
		--(*j);
		if (*j < 0)
		{
			len = ft_bin_to_len(str_pid);
			str = (char *)gmalloc(sizeof(char) * (len + 1));
		}
	}
}

void		ft_signal_pid(int sign)
{
	static int		i = 31;
	static int		j = 31;

	if (nb_bit == len && len != 0)
	{
		i = 31;
		j = 31;
		nb_bit = 0;
		len = 0;
	}
	if (i < 0)
		ft_signal_len(sign, &j);
	else
	{
		if (sign == SIGUSR1)
			str_pid[i] = '1';
		else if (sign == SIGUSR2)
			str_pid[i] = '0';
		--i;
		if (i < 0)
			ft_bin_to_pid(str_pid);
	}
}

int			main(void)
{
	int		j;

	nb_bit = 0;
	len = 0;
	ft_putnbr(getpid());
	ft_putchar('\n');
	j = 0;
	while (j < 8)
	{
		one_byte[j] = '0';
		++j;
	}
	j = 0;
	while (j < 32)
	{
		str_pid[j] = '0';
		++j;
	}
	j = 0;
	while (j < 32)
	{
		str_len[j] = '0';
		++j;
	}
	signal(SIGUSR1, ft_signal_pid);
	signal(SIGUSR2, ft_signal_pid);
	while (1)
		;
	return (0);
}
