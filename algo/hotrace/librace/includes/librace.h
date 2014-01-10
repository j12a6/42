/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 11:44:25 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/14 20:09:52 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   LIBRACE_H
# define  LIBRACE_H

# define  BUFF_SIZE 1000

# ifndef  T_RACE
#  define T_RACE

typedef struct		s_race
{
	char			*key;
	char			*val;
	struct s_race	*next;
}					t_race;

# endif /* !T_RACE */

void		ft_bzero(void *s, size_t n);
void		ft_putchar(char c);
void		ft_putendl(char const *s);
void		ft_putstr(char const *s);
char		*ft_strcat(char *s1, const char *s2);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strsub(char const *s, unsigned int starts, size_t len);
int			get_next_line(int const fd, char **line);

#endif /* LIBRACE_H */
