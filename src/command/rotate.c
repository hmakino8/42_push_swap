/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:15:39 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/19 18:06:58 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_a(t_data *d)
{
	t_lst	*fr;
	t_lst	*rr;

	if (!d->a_fr)
		return ;
	rr = create_lst(d->a_fr->val, d->a_fr->part);
	push_back(&d->a_rr, rr);
	d->a_rr = rr;
	fr = d->a_fr;
	d->a_fr = d->a_fr->next;
	delete_node(fr);
}

void	rotate_b(t_data *d)
{
	t_lst	*fr;
	t_lst	*rr;

	if (!d->b_fr)
		return ;
	rr = create_lst(d->b_fr->val, d->b_fr->part);
	push_back(&d->b_rr, rr);
	d->b_rr = rr;
	fr = d->b_fr;
	d->b_fr = d->b_fr->next;
	delete_node(fr);
}

void	r_rotate_a(t_data *d)
{
	t_lst	*fr;
	t_lst	*rr;

	if (!d->a_fr || d->a_fr == d->a_rr)
		return ;
	fr = create_lst(d->a_rr->val, d->a_rr->part);
	push_front(d->a_fr, fr);
	d->a_fr = fr;
	rr = d->a_fr;
	while (rr->next != d->a_rr)
		rr = rr->next;
	delete_node(d->a_rr);
	d->a_rr = rr;
	d->a_rr->next = NULL;
}

void	r_rotate_b(t_data *d)
{
	t_lst	*fr;
	t_lst	*rr;

	if (!d->b_fr || d->b_fr == d->b_rr)
		return ;
	fr = create_lst(d->b_rr->val, d->b_rr->part);
	push_front(d->b_fr, fr);
	d->b_fr = fr;
	rr = d->b_fr;
	while (rr->next != d->b_rr)
		rr = rr->next;
	delete_node(d->b_rr);
	d->b_rr = rr;
	d->b_rr->next = NULL;
}
