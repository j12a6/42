/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_priority_operand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 11:48:19 by makoudad          #+#    #+#             */
/*   Updated: 2014/03/04 18:07:43 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static t_p		*ft_check_if_type_to_split(t_p *p, int type)
{
	t_p		*move;
	int		ind_pth;

	move = p;
	ind_pth = 0;
	while (move)
	{
		if (move->type == PTH_B)
			++ind_pth;
		else if (move->type == PTH_E)
			--ind_pth;
		else if (ind_pth == 0 && move->type == type)
			return (move);
		move = move->next;
	}
	return (move);
}

static void		ft_find_priority_between_or_and_and(t_p **keep)
{
	int		ind_pth;

	ind_pth = 0;
	while (*keep)
	{
		if ((*keep)->type == PTH_B)
			++ind_pth;
		else if ((*keep)->type == PTH_E)
			--ind_pth;
		else if (ind_pth == 0
				&& ((*keep)->type == AND || (*keep)->type == OR))
			break ;
		*keep = (*keep)->next;
	}
}

static void		ft_find_priority_between_all_the_redir(t_p **keep)
{
	int		ind_pth;

	ind_pth = 0;
	while (*keep)
	{
		if ((*keep)->type == PTH_B)
			++ind_pth;
		else if ((*keep)->type == PTH_E)
			--ind_pth;
		else if (ind_pth == 0 && ((*keep)->type == RED_R
									|| (*keep)->type == RED_DR
									|| (*keep)->type == RED_L))
			break ;
		*keep = (*keep)->next;
	}
}

void			ft_find_priority_operand(t_p **keep, int *type)
{
	t_p		*move;

	if ((move = ft_check_if_type_to_split(*keep, SEMI_C))
		|| (move = ft_check_if_type_to_split(*keep, OR))
		|| (move = ft_check_if_type_to_split(*keep, AND))
		|| (move = ft_check_if_type_to_split(*keep, PIPE))
		|| (move = ft_check_if_type_to_split(*keep, RED_R))
		|| (move = ft_check_if_type_to_split(*keep, RED_DR))
		|| (move = ft_check_if_type_to_split(*keep, RED_L)))
		*type = move->type;
	if (*type == OR)
		ft_find_priority_between_or_and_and(keep);
	else if (*type == RED_R || *type == RED_DR)
		ft_find_priority_between_all_the_redir(keep);
	else if (*type)
		*keep = move;
}
