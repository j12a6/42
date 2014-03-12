/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxical_analyzer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:26:51 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:10:11 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "libft.h"

int		ft_error_msg(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putendl_fd(s2, 2);
	return (-1);
}

int		ft_check_wrong_nb_of_pth(t_p *p)
{
	t_p		*move;
	int		ind_pth;

	ind_pth = 0;
	move = p;
	while (move)
	{
		if ((move->type == PTH_B && move->prev
			&& (move->prev->type == WORD || move->prev->type == PTH_E))
			|| (move->type == PTH_E && move->next
				&& (move->next->type == WORD || move->next->type == PTH_B)))
			return (ft_error_msg("Badly placed ", "()'s"));
		if (move->type == PTH_B)
			++ind_pth;
		if (move->type == PTH_E)
			--ind_pth;
		if (ind_pth < 0)
			return (ft_error_msg("Too many ", ")'s."));
		move = move->next;
	}
	if (ind_pth > 0)
		return (ft_error_msg("Too many ", "('s."));
	return (0);
}

int		ft_syntaxical_analyzer(t_tree **t)
{
	int		ind_pth;
	t_p		*keep;
	int		type;

	ind_pth = 0;
	keep = (*t)->p;
	type = 0;
	ft_find_priority_operand(&keep, &type);
	if (type == 0 && (*t)->p->type != PTH_B)
		return (0);
	else if (type == 0)
	{
		if (ft_put_parenthesis_in_tree(t) == -1)
			return (-1);
		return (ft_syntaxical_analyzer(&((*t)->le)));
	}
	if (!keep->next || !keep->prev)
		return (ft_error_msg("Badly placed ", keep->tok));
	if (ft_new_tree_elem(t, keep) == -1)
		return (-1);
	return (0);
}
