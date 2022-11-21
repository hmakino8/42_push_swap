/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_white_sp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:30:41 by hiroaki           #+#    #+#             */
/*   Updated: 2022/11/22 07:12:47 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	**free_all_element(char **s, int i)
{
	while (i--)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	return (NULL);
}

static size_t	element_cnt(char *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (!ft_isspace(*(s++)))
		{
			cnt++;
			while (*s && !ft_isspace(*s))
				s++;
		}
	}
	return (cnt);
}

static char	**element_cpy(char *s, char **split, int *cnt)
{
	int		i;
	int		len;

	i = 0;
	while (*s && i < *cnt)
	{
		len = 0;
		while (*s && ft_isspace(*s))
			s++;
		while (*(s + len) && !ft_isspace(*(s + len)))
			len++;
		if (len)
		{
			split[i] = ft_substr(s, 0, len);
			if (!(split[i]))
				return (free_all_element(&split[i], i));
			i++;
		}
		s += len;
	}
	split[i] = NULL;
	return (split);
}

char	**split_white_sp(char *s, int *cnt)
{
	char	**split;

	if (!s)
		return (NULL);
	*cnt = element_cnt(s);
	split = (char **)malloc((*cnt + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (element_cpy(s, split, cnt));
}
