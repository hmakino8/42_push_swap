/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colored_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:47:30 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/18 21:07:37 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	colored_cmd(int cmd)
{
	if (cmd == PA)
		ft_printf("\x1b[01;31mPA\x1b[0m");
	else if (cmd == PB)
		ft_printf("\x1b[01;34mPB\x1b[0m");
	else if (cmd == SA)
		ft_printf("\x1b[35mSA\x1b[0m");
	else if (cmd == SB)
		ft_printf("\x1b[36mSB\x1b[0m");
	else if (cmd == SS)
		ft_printf("\x1b[01;33mSS\x1b[0m");
	else if (cmd == RA)
		ft_printf("\x1b[01;30mRA\x1b[0m");
	else if (cmd == RB)
		ft_printf("\x1b[01;30mRB\x1b[0m");
	else if (cmd == RR)
		ft_printf("\x1b[01;33mRR\x1b[0m");
	else if (cmd == RRA)
		ft_printf("\x1b[01;30mRRA\x1b[0m");
	else if (cmd == RRB)
		ft_printf("\x1b[01;30mRRB\x1b[0m");
	else if (cmd == RRR)
		ft_printf("\x1b[01;33mRRR\x1b[0m");
}

void	print_colored_cmd(t_data *d)
{
	int	i;

	i = d->cmdcnt - 1;
	ft_printf("\x1b[01;30m[\x1b[0m");
	while (0 <= i && d->cmdcnt - i <= 20)
	{
		replace_cmd(&d->arr.cmds[i], &d->arr.cmds[i + 1]);
		if (d->arr.cmds[i] == EMPTY)
			ft_printf(",\x1b[30m(REPL)\x1b[0m");
		else if (d->cmdcnt - i > 1)
			ft_printf(",");
		if (i == d->cmdcnt - 1)
			ft_printf("\x1b[32mCOMMAND => \x1b[0m");
		colored_cmd(d->arr.cmds[i]);
		i--;
	}
	ft_printf("\x1b[01;30m]\x1b[0m");
}
