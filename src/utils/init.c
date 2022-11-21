/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:40:03 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/22 07:37:21 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_lst_a(t_data *d)
{
	t_lst	*new;
	int		i;

	cord_comp(d);
	i = -1;
	while (++i < d->totalsize)
	{
		new = create_lst(d->arr.comp[i], false);
		if (!new)
			ps_exit(d, HAS_MESSAGE);
		push_back(&d->a, new);
		if (i == 0)
			push_back(&d->a_fr, new);
	}
	d->a_rr = search_last(d->a_fr);
}

void	init_array(t_data *d, char *elem[])
{
	d->arr.init = (int *)malloc(sizeof(int) * d->arr_allocsize);
	d->arr.comp = (int *)malloc(sizeof(int) * d->arr_allocsize);
	d->arr.sort = (int *)malloc(sizeof(int) * d->arr_allocsize);
	d->arr.cmds = (int *)malloc(sizeof(int) * d->cmdlimit);
	if (!d->arr.init || !d->arr.comp || !d->arr.sort || !d->arr.cmds)
		ps_exit(d, HAS_MESSAGE);
	atoi_split(d, elem);
}

static void	check_size(t_data *d, int argc)
{
	if (argc <= 1)
		ps_exit(d, NO_MESSAGE);
}

static int	arr_allocsize(char *elem[])
{
	int	i;
	int	allocsize;

	allocsize = 0;
	i = -1;
	while (elem[++i])
		allocsize += ft_strlen(elem[i]);
	return (allocsize);
}

void	init_data(t_data *d, int argc, char *elem[])
{
	d->a = NULL;
	d->a_fr = NULL;
	d->b_fr = NULL;
	d->a_rr = NULL;
	d->b_rr = NULL;
	d->arr.init = NULL;
	d->arr.comp = NULL;
	d->arr.sort = NULL;
	d->arr.cmds = NULL;
	d->max = -1;
	d->pivot = 0;
	d->elemcnt = 0;
	d->cmdcnt = 0;
	d->cmdlimit = 6000;
	d->min = INT_MAX;
	d->arr_allocsize = arr_allocsize(elem);
	d->totalsize = 0;
	check_size(d, argc);
}
