/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:19:07 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/17 04:11:17 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	delete_lst(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}

void	delete_node(t_lst *lst)
{
	if (!lst)
		return ;
	free(lst);
	lst = NULL;
}

void	delete_arr(t_data *d)
{
	free(d->arr.init);
	free(d->arr.comp);
	free(d->arr.sort);
	free(d->arr.cmds);
	d->arr.init = NULL;
	d->arr.comp = NULL;
	d->arr.sort = NULL;
	d->arr.cmds = NULL;
}
