/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:08:05 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/22 07:21:47 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_swap(int argc, char *argv[], t_data *d, bool checker)
{
	init_data(d, argc, argv + 1);
	init_array(d, argv + 1);
	init_lst_a(d);
	if (checker)
		return ;
	sort_lst(d);
	print_cmd(d->arr.cmds, d->cmdcnt);
	ps_exit(d, NO_MESSAGE);
}
