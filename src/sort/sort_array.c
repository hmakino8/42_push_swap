/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:00:28 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/19 21:14:17 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	copy_array(t_arr *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		arr->sort[i] = arr->init[i];
}

void	swap_value(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	sort_array(t_data *d, t_arr arr[], int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (arr->sort[i] >= arr->sort[j])
			{
				if (arr->sort[i] == arr->sort[j])
					ps_exit(d, HAS_MESSAGE);
				swap_value(&arr->sort[i], &arr->sort[j]);
			}
		}
	}
}

static void	comp(t_arr arr[], int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (arr->init[i] == arr->sort[j])
				arr->comp[i] = j;
		}
	}
}

void	cord_comp(t_data *d)
{
	copy_array(&d->arr, d->totalsize);
	sort_array(d, &d->arr, d->totalsize);
	comp(&d->arr, d->totalsize);
}
