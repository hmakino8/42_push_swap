/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:05:08 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/17 15:30:57 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	lstsize_v(t_lst *lst, int v)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst && lst->val != v)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	push_front(t_lst *lst, t_lst *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		lst = new;
		new->next = NULL;
		return ;
	}
	new->next = lst;
	lst = new;
}

void	push_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = search_last(*lst);
		last->next = new;
	}
}

t_lst	*create_lst(int val, bool part)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->val = val;
	new->part = part;
	new->next = NULL;
	return (new);
}
