/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:36:03 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/17 15:02:53 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_a(t_data *d)
{
	if (d->a_fr->part)
		d->a_fr->part = false;
	while (!d->a_fr->part && d->a_fr->val != TOP)
		optimize_exec_cmd(d, PB);
}

static void	sort_b(t_data *d)
{
	while (d->b_fr)
	{
		d->a_fr->part = true;
		scan_lst_n(d, d->b_fr, lstsize_v(d->b_fr, ALL));
		d->pivot = d->mid;
		while (d->b_fr && d->max > d->pivot)
		{
			if (d->b_fr->val > d->pivot)
				optimize_exec_cmd(d, PA);
			else
				optimize_exec_cmd(d, RB);
			scan_lst_n(d, d->b_fr, lstsize_v(d->b_fr, ALL));
		}
	}
}

static void	devide_by_size(t_data *d)
{
	exec_cmd(d, RA, 1);
	if (!d->b_rr)
		return ;
	if (d->b_rr->val != TOP && d->b_fr->val <= d->mid / 2)
		exec_cmd(d, RB, 1);
}

static void	split_in_half(t_data *d)
{
	int	size;

	d->a_need = TOP;
	size = d->totalsize;
	scan_lst_n(d, d->a_fr, size);
	while (size--)
	{
		if (d->a_fr->val == d->a_need)
		{
			exec_cmd(d, PB, 1);
			exec_cmd(d, RB, 1);
		}
		else if (d->a_fr->val <= d->mid)
			exec_cmd(d, PB, 1);
		else
			devide_by_size(d);
	}
	optimize_exec_cmd(d, EMPTY);
}

void	sort_over7(t_data *d)
{
	split_in_half(d);
	while (!is_all_sorted(d))
	{
		sort_b(d);
		sort_a(d);
	}
}
