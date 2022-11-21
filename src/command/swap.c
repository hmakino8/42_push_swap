/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:16:25 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/17 04:09:50 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_data *d)
{
	if (d->a_fr && d->a_fr->next)
		swap_value(&d->a_fr->val, &d->a_fr->next->val);
}

void	swap_b(t_data *d)
{
	if (d->b_fr && d->b_fr->next)
		swap_value(&d->b_fr->val, &d->b_fr->next->val);
}
