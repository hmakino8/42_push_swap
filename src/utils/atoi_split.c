/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:44:45 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/22 07:21:08 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	is_overflow(size_t num, int sign)
{
	if ((sign > 0 && num > INT_MAX) || \
		(sign < 0 && num > (INT_MAX + 1UL)))
		return (true);
	return (false);
}

static	int	convert_atoi(char *str, int sign, int i, bool *ok)
{
	size_t	num;

	num = 0;
	while (1)
	{
		if (!ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		num = (num * 10) + str[i++] - '0';
		if (is_overflow(num, sign))
			return (EXIT_FAILURE);
		if (!str[i])
			break ;
	}
	*ok = true;
	return ((int)num);
}

static int	ft_atoi_check(char *str, bool *ok)
{
	int				i;
	int				sign;

	i = 0;
	sign = 1;
	*ok = false;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	return (convert_atoi(str, sign, i, ok) * sign);
}

void	atoi_split(t_data *d, char *elem[])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = -1;
	while (elem[++i])
	{
		d->split = split_white_sp(elem[i], &d->elemcnt);
		if (!d->split || !d->elemcnt)
			ps_exit(d, HAS_MESSAGE);
		d->totalsize += d->elemcnt;
		j = -1;
		while (d->split[++j])
			d->arr.init[++k] = ft_atoi_check(d->split[j], &d->atoi_ok);
		if (!d->atoi_ok)
			ps_exit(d, HAS_MESSAGE);
		free_all_element(d->split, d->elemcnt);
	}
}
