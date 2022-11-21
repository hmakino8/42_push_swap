/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:08:05 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/20 13:09:35 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	d;

	push_swap(argc, argv, &d, false);
	return (EXIT_SUCCESS);
}

//__attribute__((destructor)) static void end(void)
//{
//	system("leaks -q push_swap 1>&2");
//}
//
