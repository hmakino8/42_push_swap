/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:51:35 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/17 18:19:39 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	is_sorted(t_lst *lst, int size)
{
	while (size >= 2 && lst->next)
	{
		if (lst->val > lst->next->val)
			return (false);
		lst = lst->next;
	}
	return (true);
}

bool	is_all_sorted(t_data *d)
{
	return (!d->b_fr && is_sorted(d->a_fr, d->totalsize));
}
