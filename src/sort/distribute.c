/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:55:25 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/18 19:01:10 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_lst(t_data *d)
{
	if (is_sorted(d->a_fr, d->totalsize))
		ps_exit(d, NO_MESSAGE);
	if (d->totalsize == 2)
		exec_cmd(d, SA, 1);
	else if (d->totalsize == 3)
		sort_3(d);
	else if (d->totalsize == 4)
		sort_4(d);
	else if (d->totalsize <= 6)
		sort_5_6(d);
	else
		sort_over7(d);
}
