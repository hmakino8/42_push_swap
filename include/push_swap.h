/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:08:02 by hmakino           #+#    #+#             */
/*   Updated: 2022/11/22 07:30:46 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> /* for visualizer */
# include <stdbool.h>
# include "../libs/include/libft.h"
# include "../libs/include/ft_print.h"
# include "../libs/include/get_next_line.h"

# ifdef VIS
#  define VIS 1
# else
#  define VIS 0
# endif

//# ifdef VIS
//#  define ft_printf(...) printf(__VA_ARGS__)
//# endif

# define STD_OUT 1
# define STD_ERROR 2

enum e_signal {
	ALL = -1,
	TOP,
	TO_A,
	TO_B,
	NO_MESSAGE,
	HAS_MESSAGE,
	SORTED,
	UNSORTED
};

enum e_command {
	DAMY = 0,
	EMPTY,
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct s_arr
{
	int	*init;
	int	*sort;
	int	*comp;
	int	*cmds;
}	t_arr;

typedef struct s_lst
{
	int				val;
	bool			part;
	struct s_lst	*next;
}	t_lst;

typedef struct s_data
{
	int		max;
	int		mid;
	int		min;
	int		pivot;
	int		a_need;
	int		cmdcnt;
	int		cmdlimit;
	int		elemcnt;
	int		arr_allocsize;
	int		totalsize;
	char	**elem;
	char	**split;
	bool	atoi_ok;
	t_arr	arr;
	t_lst	*a;
	t_lst	*a_fr;
	t_lst	*b_fr;
	t_lst	*a_rr;
	t_lst	*b_rr;
}	t_data;

/* push_swap.c */
void	push_swap(int argc, char *argv[], t_data *d, bool checker);

/* * * * * * * *
 * command dir *
 * * * * * * * */

/* exec_cmd.c */
void	exec_cmd(t_data *d, int cmd, int n);
/* optimize.c */
void	optimize_exec_cmd(t_data *d, int cmd);
/* print_cmd.c */
void	replace_cmd(int *l, int *r);
void	print_cmd(int cmds[], int size);
/* push.c */
void	push_a(t_data *d);
void	push_b(t_data *d);
/* rotate.c */
void	rotate_a(t_data *d);
void	rotate_b(t_data *d);
void	r_rotate_a(t_data *d);;
void	r_rotate_b(t_data *d);
/* swap.c */
void	swap_a(t_data *d);
void	swap_b(t_data *d);

/* * * * * * *
 * sort dir  *
 * * * * * * */

/* distribute.c */
void	sort_lst(t_data *d);
/* sort_array.c */
void	swap_value(int *x, int *y);
void	cord_comp(t_data *d);
void	sort_array(t_data *d, t_arr arr[], int size);
/* under7.c */
void	sort_3(t_data *d);
void	sort_4(t_data *d);
void	sort_5_6(t_data *d);
/* over7.c */
void	sort_over7(t_data *d);

/* * * * * * *
 * utils dir *
 * * * * * * */

/* cmd_arr_realloc.c */
void	cmd_arr_realloc(t_data *d);
/* check.c */
bool	is_all_sorted(t_data *d);
bool	is_sorted(t_lst *lst, int size);
/* delete.c */
void	delete_arr(t_data *d);
void	delete_lst(t_lst *lst);
void	delete_node(t_lst *lst);
/* atoi_split.c */
void	atoi_split(t_data *d, char *elem[]);
/* split_white_sp.c */
char	**free_all_element(char **s, int i);
char	**split_white_sp(char *s, int *cnt);
/* init.c */
void	init_lst_a(t_data *d);
void	init_array(t_data *d, char *elem[]);
void	init_data(t_data *d, int argc, char *elem[]);
/* parse.c */
t_lst	*search_last(t_lst *lst);
int		search_locate(t_lst *lst, int size, int v);
void	scan_lst_n(t_data *d, t_lst *lst, int n);
/* list_operate.c */
t_lst	*create_lst(int val, bool part);
int		lstsize_v(t_lst *lst, int v);
void	push_front(t_lst *lst, t_lst *new);
void	push_back(t_lst **lst, t_lst *new);
/* exit.c */
void	ps_exit(t_data *d, int signal);

/* * * * * * * * * *
 * visualizer dir  *
 * * * * * * * * * */

/* print_colored_cmd.c */
void	print_colored_cmd(t_data *d);
/* visualizer.c */
void	visualizer(t_data *d);

#endif
