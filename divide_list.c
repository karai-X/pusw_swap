/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:28:53 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 11:30:35 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*divide_list_part1(t_list *alist, t_list *blist, t_list *ans_list,
		int move_block_blen_sn[4])
{
	while (move_block_blen_sn[2] - move_block_blen_sn[0] > 3
		&& move_block_blen_sn[0] < 3)
	{
		if (list_gd(blist, 0) == ans_list->bottom + 2 && list_gd(blist,
				1) == ans_list->bottom + 1)
		{
			if (list_swap_ans(blist, ans_list)==NULL)
				return (NULL);
		}
		if (list_gd(blist, 0) > move_block_blen_sn[3] + 2)
			move_block_blen_sn[0] += 1;
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
		else if (list_gd(blist, 0) <= move_block_blen_sn[3] + 2)
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
			move_block_blen_sn[1] += 1;
		}
	}
	return (ans_list);
}

t_list	*divide_list(t_list *alist, t_list *blist, t_list *ans_list,
		int *block_cnt)
{
	int	move_block_blen_sn[4];

	move_block_blen_sn[0] = 0;
	move_block_blen_sn[1] = *block_cnt;
	move_block_blen_sn[2] = blist->len;
	move_block_blen_sn[3] = list_min(blist);
	if (blist->len <= 11)
	{
		if (move_block_blen_sn[2] > 6)
			move_block_blen_sn[3] = move_block_blen_sn[3]
				+ move_block_blen_sn[2] - 6;
		if (divide_list_part1(alist, blist, ans_list,
				move_block_blen_sn) == NULL)
			return (NULL);
	}
	else
	{
		while (move_block_blen_sn[0] < move_block_blen_sn[2] / 2)
		{
			if (list_gd(blist, 0) > move_block_blen_sn[3]
				+ (move_block_blen_sn[2] - 1) / 2)
				move_block_blen_sn[0] += 1;
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
			else if (list_gd(blist, 0) <= move_block_blen_sn[3]
				+ (move_block_blen_sn[2] - 1) / 2)
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
				move_block_blen_sn[1] += 1;
			}
		}
	}
	*block_cnt = move_block_blen_sn[1];
	return (ans_list);
}
