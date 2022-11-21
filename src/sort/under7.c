/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:31:21 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/18 19:02:44 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	is_simple_case(t_data *d)
{
	int		cmd;

	cmd = EMPTY;
	swap_a(d);
	if (is_sorted(d->a_fr, d->totalsize))
		cmd = SA;
	swap_a(d);
	rotate_a(d);
	if (is_sorted(d->a_fr, d->totalsize))
		cmd = RA;
	r_rotate_a(d);
	r_rotate_a(d);
	if (is_sorted(d->a_fr, d->totalsize))
		cmd = RRA;
	rotate_a(d);
	if (cmd == EMPTY)
		return (false);
	exec_cmd(d, cmd, 1);
	return (true);
}

static void	r_sort_3(t_data *d)
{
	scan_lst_n(d, d->b_fr, 3);
	if (d->b_fr->val == d->max && d->b_fr->next->val == d->mid)
		return ;
	if (d->b_fr->val == d->max)
		exec_cmd(d, RB, 1);
	if (d->b_fr->val == d->mid)
	{
		if (d->b_rr->val == d->min)
			exec_cmd(d, SB, 1);
		else
			exec_cmd(d, RRB, 1);
	}
	if (d->b_fr->val == d->min)
	{
		if (d->b_rr->val == d->max)
		{
			exec_cmd(d, SB, 1);
			exec_cmd(d, RRB, 1);
		}
		else
			exec_cmd(d, RRB, 2);
	}
}

void	sort_3(t_data *d)
{
	if (is_sorted(d->a_fr, 3))
		return ;
	scan_lst_n(d, d->a_fr, 3);
	if (d->a_fr->val == d->min)
		exec_cmd(d, RA, 1);
	if (d->a_fr->val == d->max)
	{
		if (d->a_rr->val == d->min)
			exec_cmd(d, SA, 1);
		exec_cmd(d, RRA, 1);
	}
	if (d->a_fr->val == d->mid)
	{
		if (d->a_rr->val == d->max)
			exec_cmd(d, SA, 1);
		else
			exec_cmd(d, RRA, 1);
	}
}

void	sort_4(t_data *d)
{
	if (d->a_fr->val == 2)
		exec_cmd(d, SA, 1);
	exec_cmd(d, PB, 1);
	sort_3(d);
	exec_cmd(d, PA, 1);
	if (d->a_fr->val == 1)
		exec_cmd(d, SA, 1);
	if (d->a_fr->val == 3)
		exec_cmd(d, RA, 1);
}

void	sort_5_6(t_data *d)
{
	scan_lst_n(d, d->a_fr, d->totalsize);
	if (is_simple_case(d))
		return ;
	while (lstsize_v(d->a_fr, ALL) != 3)
	{
		if (d->a_fr->val < d->mid)
			exec_cmd(d, PB, 1);
		else
			exec_cmd(d, RA, 1);
	}
	sort_3(d);
	if (d->totalsize == 5)
	{
		if (d->b_fr->val == 0)
			exec_cmd(d, SB, 1);
		exec_cmd(d, PA, 2);
		return ;
	}
	r_sort_3(d);
	exec_cmd(d, PA, 3);
}
