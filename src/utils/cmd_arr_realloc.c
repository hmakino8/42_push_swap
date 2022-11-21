/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arr_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:28:19 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/22 07:31:48 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	cmd_arr_realloc(t_data *d)
{
	int	*new;

	new = (int *)malloc(sizeof(int) * d->cmdlimit * 2);
	if (!new)
		ps_exit(d, HAS_MESSAGE);
	free(d->arr.cmds);
	d->arr.cmds = new;
	d->cmdlimit *= 2;
}
