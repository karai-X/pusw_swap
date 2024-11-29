/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:28:53 by karai             #+#    #+#             */
/*   Updated: 2024/11/29 21:39:45 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*divide_list(t_list *alist, t_list *blist, t_list *ans_list,
		int *block_cnt)
{
	int	init_blist_len;
	int	sn;
	int	move_cnt;

	init_blist_len = blist->len;
	sn = list_min(blist);
	move_cnt = 0;
	if (blist->len <= 11)
	{
		if (init_blist_len > 6)
			sn = sn + init_blist_len - 6;
		while (init_blist_len - move_cnt > 3 && move_cnt < 3)
		{
			if (list_gd(blist, 0) == ans_list->bottom + 2 && list_gd(blist,
					1) == ans_list->bottom + 1)
			{
				list_swap(blist, 0);
				list_append(ans_list, SB);
			}
			if (list_gd(blist, 0) > sn + 2)
				move_cnt += 1;
			if (list_gd(blist, 0) == (ans_list->bottom + 1))
			{
				if (list_last(ans_list) == PB)
					list_remove_right(ans_list);
				else
					list_append(ans_list, PA);
				list_appendleft(alist, list_gd(blist, 0));
				list_remove_left(blist);
				list_rotate_left(alist);
				list_append(ans_list, RA);
				ans_list->bottom += 1;
			}
			else if (list_gd(blist, 0) <= sn + 2)
			{
				list_rotate_left(blist);
				list_append(ans_list, RB);
			}
			else
			{
				if (list_last(ans_list) == PB)
					list_remove_right(ans_list);
				else
					list_append(ans_list, PA);
				list_appendleft(alist, list_gd(blist, 0));
				list_remove_left(blist);
				*block_cnt += 1;
			}
		}
	}
	else
	{
		while (move_cnt < init_blist_len / 2)
		{
			if (list_gd(blist, 0) > sn + (init_blist_len - 1) / 2)
				move_cnt += 1;
			if (list_gd(blist, 0) == ans_list->bottom + 1)
			{
				if (list_last(ans_list) == PB)
					list_remove_right(ans_list);
				else
					list_append(ans_list, PA);
				list_appendleft(alist, list_gd(blist, 0));
				list_remove_left(blist);
				list_rotate_left(alist);
				list_append(ans_list, RA);
				ans_list->bottom += 1;
			}
			else if (list_gd(blist, 0) <= sn + (init_blist_len - 1) / 2)
			{
				list_rotate_left(blist);
				list_append(ans_list, RA + blist->idx);
			}
			else
			{
				if (list_last(ans_list) == PB)
					list_remove_right(ans_list);
				else
					list_append(ans_list, PA);
				list_appendleft(alist, list_gd(blist, 0));
				list_remove_left(blist);
				*block_cnt += 1;
			}
		}
	}
	return (ans_list);
}
