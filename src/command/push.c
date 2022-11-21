/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:14:47 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/19 21:23:33 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_a(t_data *d)
{
	t_lst	*a_fr;
	t_lst	*b_fr;

	if (!d->b_fr)
		return ;
	a_fr = create_lst(d->b_fr->val, d->b_fr->part);
	push_front(d->a_fr, a_fr);
	d->a_fr = a_fr;
	if (!d->a_rr)
		d->a_rr = d->a_fr;
	b_fr = d->b_fr;
	d->b_fr = d->b_fr->next;
	if (!d->b_fr)
		d->b_rr = NULL;
	delete_node(b_fr);
}

void	push_b(t_data *d)
{
	t_lst	*a_fr;
	t_lst	*b_fr;

	if (!d->a_fr)
		return ;
	b_fr = create_lst(d->a_fr->val, d->a_fr->part);
	push_front(d->b_fr, b_fr);
	d->b_fr = b_fr;
	if (!d->b_rr)
		d->b_rr = d->b_fr;
	a_fr = d->a_fr;
	d->a_fr = d->a_fr->next;
	if (!d->a_fr)
		d->a_rr = NULL;
	delete_node(a_fr);
}
