/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:42:08 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/17 14:57:58 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	optimize_a(t_data *d)
{
	int	size;

	size = lstsize_v(d->a_fr, ALL);
	if (d->a_fr->next->val == d->a_need && size >= 2)
		exec_cmd(d, SA, 1);
}

static void	optimize_b(t_data *d)
{
	int	size;

	if (!d->b_fr)
		return ;
	size = lstsize_v(d->b_fr, ALL);
	if (d->b_fr->next)
	{
		if (d->b_fr->val > d->b_fr->next->val && \
			d->b_fr->next->val == d->a_need && size >= 10)
			exec_cmd(d, SB, 1);
		if (d->b_fr->next->val == d->a_need)
			exec_cmd(d, RB, 1);
	}
	if (d->b_rr)
	{
		if (size >= 4 && search_locate(d->b_fr, size, d->a_need) == size - 1)
			exec_cmd(d, RRB, 2);
		if (size >= 3 && d->b_rr && d->b_rr->val == d->a_need)
			exec_cmd(d, RRB, 1);
	}
	if (d->b_fr->val == d->a_need)
		optimize_exec_cmd(d, PA);
}

void	optimize_exec_cmd(t_data *d, int cmd)
{
	exec_cmd(d, cmd, 1);
	optimize_a(d);
	optimize_b(d);
	if (d->a_fr->val == d->a_need)
	{
		d->a_need++;
		optimize_exec_cmd(d, RA);
	}
}
