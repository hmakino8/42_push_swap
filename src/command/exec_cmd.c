/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:26:37 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/22 07:29:18 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	check_cmd_overflow(t_data *d)
{
	if (d->cmdcnt < d->cmdlimit)
		return ;
	cmd_arr_realloc(d);
}

void	exec_cmd(t_data *d, int cmd, int n)
{
	if (cmd == EMPTY)
		return ;
	while (n--)
	{
		if (cmd == PA)
			push_a(d);
		if (cmd == PB)
			push_b(d);
		if (cmd == SA)
			swap_a(d);
		if (cmd == SB)
			swap_b(d);
		if (cmd == RA)
			rotate_a(d);
		if (cmd == RB)
			rotate_b(d);
		if (cmd == RRA)
			r_rotate_a(d);
		if (cmd == RRB)
			r_rotate_b(d);
		d->arr.cmds[d->cmdcnt++] = cmd;
		check_cmd_overflow(d);
	}
	if (VIS)
		visualizer(d);
}
