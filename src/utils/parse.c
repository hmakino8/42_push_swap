/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   investigate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:07:38 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/17 04:12:12 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	scan_lst_n(t_data *d, t_lst *lst, int n)
{
	int	i;

	if (n <= 0)
		return ;
	i = -1;
	while (++i < n)
	{
		d->arr.sort[i] = lst->val;
		lst = lst->next;
	}
	sort_array(d, &d->arr, n);
	d->min = d->arr.sort[0];
	d->mid = d->arr.sort[n / 2];
	d->max = d->arr.sort[n - 1];
}

t_lst	*search_last(t_lst *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	search_locate(t_lst *lst, int size, int v)
{
	int	l;

	if (!lst || !size)
		return (-1);
	l = 1;
	while (l++ <= size && lst->val != v)
		lst = lst->next;
	if (l > size)
		return (0);
	return (l);
}
