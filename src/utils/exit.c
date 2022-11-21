/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:17:40 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/19 15:13:01 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ps_exit(t_data *d, int signal)
{
	delete_lst(d->a_fr);
	delete_lst(d->b_fr);
	delete_arr(d);
	if (signal == NO_MESSAGE)
		exit(EXIT_SUCCESS);
	ft_dprintf(STD_ERROR, "%s\n", "Error");
	exit(EXIT_FAILURE);
}
