/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 12:10:29 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/22 12:20:24 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PRINTF_H
# define	FT_PRINTF_H

#include <string.h>
#include <stdlib.h>

# define	BUFF	1000

# ifndef	T_STRUCT
#  define	T_STRUCT

typedef struct			s_struct
{
	size_t				i;
	size_t				j;
	size_t				len;
	ssize_t				tot;
}						t_struct;

# endif	/* !T_STRUCT */

ssize_t			ft_putchar(char c);
size_t			ft_strlen(const char *s);
ssize_t			ft_putstr(const char *s);
ssize_t			ft_putnbr(int n);
ssize_t			ft_putnbr_long(unsigned int n);
ssize_t			ft_putbase(unsigned int n, char *base);
ssize_t			ft_putendl(const char *s);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
ssize_t			ft_printf(const char *format, ...);

#endif	/* !FT_PRINTF_H */
