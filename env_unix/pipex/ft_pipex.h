/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:28:13 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/31 16:55:09 by lcharpen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PIPEX_H
# define	FT_PIPEX_H

# ifndef	T_PIPEX
#  define	T_PIPEX

typedef struct		s_pipex
{
	char			*file1;
	char			*cmd1;
	char			*file2;
	char			*cmd2;
}					t_pipex;

# endif	/* !T_PIPEX */

# ifndef	T_FD
#  define	T_FD

typedef struct		s_fd
{
	int				fd1;
	int				fd2;
	int				fd_tmp;
}					t_fd;

# endif	/* !T_FD */

int		ft_init_struct(char **av, char **env, t_pipex *pipex, t_fd *fd);

#endif	/* !FT_PIPEX_H */
