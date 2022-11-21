/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:44:10 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/20 13:26:40 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/push_swap.h"

static void	vis_a(t_data *d, t_lst *a)
{
	bool		top;

	top = false;
	ft_printf("\n\n\x1b[31m++++ [STACK_A] ++++\x1b[0m\n");
	ft_printf("\x1b[31m[\x1b[0m");
	while (a)
	{
		if (d->a_rr->val == d->a_need - 1 && a->val == TOP)
		{
			top = true;
			ft_printf("\x1b[42mTOP[%d]\x1b[0m", a->val);
		}
		else if (top)
			ft_printf("\x1b[32m%d\x1b[0m", a->val);
		else if (a->val == d->a_need)
			ft_printf("\x1b[41mA_NEED[%d]\x1b[0m", a->val);
		else if (a->part)
			ft_printf("\x1b[46mPARTITION[%d]\x1b[0m", a->val);
		else
			ft_printf("%d", a->val);
		if (a->val != d->a_rr->val)
			ft_printf(", ");
		a = a->next;
	}
	ft_printf("\x1b[31m]\x1b[0m");
}

static void	vis_b(t_data *d, t_lst *b)
{
	ft_printf("\n\n\x1b[34m++++ [STACK_B] ++++\x1b[0m\n");
	if (d->b_fr)
		ft_printf("\x1b[34m[\x1b[0m");
	else
		ft_printf("(null)");
	while (b)
	{
		if (d->pivot && b->val == d->pivot)
			ft_printf("\x1b[43mPIVOT[%d]\x1b[0m", d->pivot);
		else if (b->val == d->a_need)
			ft_printf("\x1b[41mA_NEED[%d]\x1b[0m", b->val);
		else
			ft_printf("%d", b->val);
		if (b->val != d->b_rr->val)
			ft_printf(", ");
		b = b->next;
	}
	if (d->b_fr)
		ft_printf("\x1b[34m]\x1b[0m");
}

static void	redraw(void)
{
	fflush(stdout);
	usleep((double)100000);
	ft_printf("\x1b[1J");
	ft_printf("\x1b[0;0H");
}

void	visualizer(t_data *d)
{
	print_colored_cmd(d);
	vis_a(d, d->a_fr);
	vis_b(d, d->b_fr);
	if (is_all_sorted(d))
		sleep(15);
	redraw();
}
