/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:44:25 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/07 15:18:58 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LIBFT_H
# define	LIBFT_H

# define	BUFF_SIZE 1

# include	<string.h>
# include	<stdarg.h>

# ifndef T_LIST
#  define T_LIST

typedef struct		s_mal
{
	void			*s;
	struct s_mal	*next;
	struct s_mal	*prev;
}					t_mal;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

# endif

void				*c_calls(char *str, char *s1);
void				*c_calld(char *str, char *s1, char *s2);
int					cfree(void);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_char2_len(char **str);
char				**ft_copy_ts(char **ts);
void				ft_error(char *error, char *str);
int					ft_find(char *s1, char *s2);
int					ft_free_char2(char **s);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
int					ft_list_mal(int i, void *s);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lstt, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_put_base(unsigned int n, char *base);
void				ft_put_char2(char **s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
double				ft_sqrt(double n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s,
								char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplim(char const *s);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start,
							   size_t len);
char				*ft_strtrim(char const *s);
char				*ft_toa(unsigned int n, char *base);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wc_w(char const *s, char c);
int					get_next_line(int const fd, char **line);
int					gfree(void *s);
void				*gmalloc(size_t size);
char				*grealloc(char *old, size_t size);

#endif	/* !LIBFT_H */
