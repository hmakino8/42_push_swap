/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:24:34 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/19 03:50:15 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	convert_cmd(int cmd)
{
	if (cmd == SA)
		ft_dprintf(STD_OUT, "%s\n", "sa");
	if (cmd == SB)
		ft_dprintf(STD_OUT, "%s\n", "sb");
	if (cmd == SS)
		ft_dprintf(STD_OUT, "%s\n", "ss");
	if (cmd == PA)
		ft_dprintf(STD_OUT, "%s\n", "pa");
	if (cmd == PB)
		ft_dprintf(STD_OUT, "%s\n", "pb");
	if (cmd == RA)
		ft_dprintf(STD_OUT, "%s\n", "ra");
	if (cmd == RB)
		ft_dprintf(STD_OUT, "%s\n", "rb");
	if (cmd == RR)
		ft_dprintf(STD_OUT, "%s\n", "rr");
	if (cmd == RRA)
		ft_dprintf(STD_OUT, "%s\n", "rra");
	if (cmd == RRB)
		ft_dprintf(STD_OUT, "%s\n", "rrb");
	if (cmd == RRR)
		ft_dprintf(STD_OUT, "%s\n", "rrr");
}

void	replace_cmd(int *l, int *r)
{
	if (((*l == PA && *r == PB) || (*l == PB && *r == PA)) || \
		((*l == SA && *r == SA) || (*l == SB && *r == SB)) || \
		((*l == RA && *r == RRA) || (*l == RRA && *r == RA)) || \
		((*l == RB && *r == RRB) || (*l == RRB && *r == RB)) || \
		((*l == RA && *r == RRA) || (*l == RRA && *r == RA)))
		*l = EMPTY;
	else if ((*l == SA && *r == SB) || (*l == SB && *r == SA))
		*l = SS;
	else if ((*l == RA && *r == RB) || (*l == RB && *r == RA))
		*l = RR;
	else if ((*l == RRA && *r == RRB) || (*l == RRB && *r == RRA))
		*l = RRR;
	else
		return ;
	*r = EMPTY;
}

void	print_cmd(int cmds[], int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (i < size - 1)
			replace_cmd(&cmds[i], &cmds[i + 1]);
		convert_cmd(cmds[i]);
	}
}
