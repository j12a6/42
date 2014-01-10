/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 12:19:15 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 19:34:54 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

static void			ft_all_opt(const char *form, va_list ap, t_struct *info)
{
	if (*(form + info->i) == '%')
	{
		info->tot += write(1, "%", 1);
		return ;
	}
	while (info->i < info->len)
	{
		if (*(form + info->i) == 'd' || *(form + info->i) == 'i')
			info->tot += ft_putnbr(va_arg(ap, int));
		if (*(form + info->i) == 'c')
			info->tot += ft_putchar((unsigned char)va_arg(ap, int));
		if (*(form + info->i) == 's')
			info->tot += ft_putstr(va_arg(ap, char *));
		if (*(form + info->i) == 'u')
			info->tot += ft_putnbr_long((unsigned int)va_arg(ap, int));
		if (*(form + info->i) == 'o')
			info->tot += ft_putbase(va_arg(ap, unsigned int), "01234567");
		if (*(form + info->i) == 'x')
			info->tot += ft_putbase(va_arg(ap, unsigned int),
									"0123456789abcdef");
		if (*(form + info->i) == 'X')
			info->tot += ft_putbase(va_arg(ap, unsigned int),
									"0123456789ABCEDF");
		info->i++;
	}
}

ssize_t				ft_printf(const char *format, ...)
{
	t_struct	*info;
	va_list		ap;

	if (!(info = (t_struct *)malloc(sizeof(t_struct))))
		return (0);
	info->i = 0;
	info->j = 0;
	info->len = ft_strlen(format);
	info->tot = 0;
	va_start(ap, format);
	while (info->i < info->len)
	{
		while (info->i < info->len && *(format + info->i) != '%')
			info->i++;
		info->tot += write(1, format + info->j, info->i - info->j);
		info->i++;
		if (info->i < info->len)
			ft_all_opt(format, ap, info);
		info->i++;
		info->j = info->i;
	}
	va_end(ap);
	return (info->tot);
}
