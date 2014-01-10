/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:08:25 by jaubert           #+#    #+#             */
/*   Updated: 2013/12/29 21:22:18 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL1_H
# define	MINISHELL1_H

void		ft_pwd(void);
void		ft_cd(char *line);
void		ft_env(char *line, char **env);
int			ft_launch_bin(char *line, char **env);
char		**ft_setenv(char *line, char **env);

#endif	/* !MINISHELL1_H */
