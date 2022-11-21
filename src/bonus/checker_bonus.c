/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:55:16 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/20 13:32:27 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	r_convert_cmd(t_data *d, char *cmd)
{
	int	cnt;

	cnt = 0;
	if ((!ft_strcmp(cmd, "sa\n") || !ft_strcmp(cmd, "ss\n")) && ++cnt)
		swap_a(d);
	if (!ft_strcmp(cmd, "pb\n") && ++cnt)
		push_b(d);
	if ((!ft_strcmp(cmd, "ra\n") || !ft_strcmp(cmd, "rr\n")) && ++cnt)
		rotate_a(d);
	if ((!ft_strcmp(cmd, "rra\n") || !ft_strcmp(cmd, "rrr\n")) && ++cnt)
		r_rotate_a(d);
	if ((!ft_strcmp(cmd, "sb\n") || !ft_strcmp(cmd, "ss\n")) && ++cnt)
		swap_b(d);
	if (!ft_strcmp(cmd, "pa\n") && ++cnt)
		push_a(d);
	if ((!ft_strcmp(cmd, "rb\n") || !ft_strcmp(cmd, "rr\n")) && ++cnt)
		rotate_b(d);
	if ((!ft_strcmp(cmd, "rrb\n") || !ft_strcmp(cmd, "rrr\n")) && ++cnt)
		r_rotate_b(d);
	return (cnt);
}

static void	exec_checker_cmd(t_data *d)
{
	char	*cmd;
	int		signal;

	while (1)
	{
		cmd = get_next_line(0, &signal);
		if (signal != NORMAL && signal != END_OF_FILE)
			break ;
		if (!cmd)
			return ;
		if (!r_convert_cmd(d, cmd))
			break ;
	}
	ps_exit(d, HAS_MESSAGE);
}

int	main(int argc, char *argv[])
{
	t_data	d;

	push_swap(argc, argv, &d, true);
	if (!d.atoi_ok)
		ps_exit(&d, HAS_MESSAGE);
	exec_checker_cmd(&d);
	if (is_all_sorted(&d))
		ft_dprintf(STD_OUT, "OK\n");
	else
		ft_dprintf(STD_OUT, "KO\n");
	ps_exit(&d, NO_MESSAGE);
	return (0);
}
