/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:35:20 by jaubert           #+#    #+#             */
/*   Updated: 2014/03/28 11:30:47 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEMIN2_H
# define	LEMIN2_H

typedef struct		s_link
{
	char			*name;
	struct s_link	*prev;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	t_link			*link;
	t_link			*tmp_link;
	struct s_room	*next;
}					t_room;

typedef struct		s_game
{
	int				nb_ant;
	int				i_start;
	int				i_end;
	char			*start;
	char			*end;
	t_room			*room;
	t_room			*tmp_room;
}					t_game;

int			ft_find_path(t_game *game, t_room *start, t_room *end, t_link **p);
void		ft_find_little_path(t_game *game, t_link **p);

int			ft_init_vars(int *index, char **line, t_game **game);
t_game		*ft_save_input(t_game *game, t_link **hist);
t_game		*ft_find_trail(t_game *game, t_link *hist);

int			ft_check_line(int index, char *line, t_game *game);

int			ft_save_line(int index, char *line, t_game *game);
void		*c_calls(char *str, char *s1);
int			ft_error(char *s1, char *s2, int ret);

/*
**	basics
*/
int			is_comment(char *line);
int			is_number(char *line);
int			where_is_c_in_str(char c, char *str);
int			how_much_c_in_str(char c, char *str);
char		*ft_get_name(char *line, char c, int i);

/*
**	basics2
*/
void		ft_print_path(t_game *game, t_link *path, t_link *hist);

/*
**	sf_check
*/
int			sf_check_room_name(char *line, t_game *game);
int			sf_check_coords_syntax(char *line);
int			sf_check_links(char *line, t_game *game);
int			ft_is_str_a_room(char *str, t_room *room);
t_room		*ft_new_room(void);

/*
**	sf_save
*/
int			set_start_end(t_game *game);
int			ft_is_str_a_link(char *str, t_link *link);
int			sf_save_link(t_room *room, char *room_name, char *link_name);
t_link		*ft_new_link(void);

#endif	/* !LEMLIN2_H */
