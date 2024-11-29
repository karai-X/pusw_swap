/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:12:04 by karai             #+#    #+#             */
/*   Updated: 2024/11/29 21:53:21 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*move_bottom_list(t_list *alist, t_list *blist, t_list *ans_list)
{
	while (list_is_empty(alist) == false)
	{
		if (list_appendleft(blist, list_gd(alist, 0)) == NULL)
			return (NULL);
		list_rotate_left(blist);
		list_remove_left(alist);
		if (list_append(ans_list, PB + alist->idx) == NULL)
			return (NULL);
		if (list_append(ans_list, RA) == NULL)
			return (NULL);
	}
	return (ans_list);
}

void	ft_dfs(t_list *alist, t_list *blist, t_list *ans_list,
		t_list *block_list)
{
	int	block_cnt;

	while (blist->len > 3)
	{
		block_cnt = 0;
		divide_list(alist, blist, ans_list, &block_cnt);
		list_appendleft(block_list, block_cnt);
	}
}

void	list_move(t_list *alist, t_list *blist, t_list *ans_list, int move_num)
{
	int	i;

	i = 0;
	while (i < move_num)
	{
		if (list_gd(alist, 0) == (ans_list->bottom + 1))
		{
			list_rotate_left(alist);
			list_append(ans_list, RA);
			ans_list->bottom += 1;
			while (list_gd(blist, 0) == (ans_list->bottom + 1))
			{
				list_appendleft(alist, list_gd(blist, 0));
				list_remove_left(blist);
				list_append(ans_list, PA);
				list_rotate_left(alist);
				list_append(ans_list, RA);
				ans_list->bottom += 1;
			}
		}
		else
		{
			list_append(ans_list, PB + alist->idx);
			list_appendleft(blist, list_gd(alist, 0));
			list_remove_left(alist);
		}
		i += 1;
	}
}

int	list_min_limit(t_list *list, int num)
{
	int	sn;
	int	i;

	sn = INT_MAX;
	i = 0;
	while (i < num)
	{
		if (list_gd(list, i) < sn)
			sn = list_gd(list, i);
		i += 1;
	}
	return (sn);
}



void	sort_list_u3_to_other(t_list *alist, t_list *blist, t_list *ans_list)
{
	int	alist_top;

	alist_top = 0;
	while (blist->len != 0)
	{
		if (list_gd(blist, 0) == ans_list->bottom + 1)
		{
			list_appendleft(alist, list_gd(blist, 0));
			list_remove_left(blist);
			list_rotate_left(alist);
			list_append(ans_list, PA);
			list_append(ans_list, RA);
			ans_list->bottom += 1;
			while (alist_top > 0)
			{
				if (list_gd(alist, 0) == ans_list->bottom + 1)
				{
					list_rotate_left(alist);
					list_append(ans_list, RA);
					ans_list->bottom += 1;
					alist_top -= 1;
				}
				else
					break ;
			}
		}
		else
		{
			list_appendleft(alist, list_gd(blist, 0));
			list_remove_left(blist);
			list_append(ans_list, PA);
			alist_top += 1;
			if (alist_top >= 2 && (list_gd(alist, 0) > list_gd(alist, 1)))
			{
				list_swap(alist, 0);
				list_append(ans_list, SA);
			}
		}
	}
}
