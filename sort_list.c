/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:12:04 by karai             #+#    #+#             */
/*   Updated: 2024/11/28 00:18:12 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

// void	sort_list_u3(t_list *list, int sn, int length, t_list *ans_list)
void	sort_list_u3(t_list *list, t_list *ans_list)
{
	int	sn;

	sn = list_min(list);
	if (list->len == 1)
		return ;
	else if (list->len == 2)
	{
		if (list_gd(list, 0) > list_gd(list, 1))
		{
			list_append(ans_list, SA + list->idx);
			list_swap(list, 0);
		}
	}
	else if (list->len == 3)
	{
		if ((list_gd(list, 0) == sn) && (list_gd(list, 1) == sn + 2))
		{
			list_append(ans_list, RRA + list->idx);
			list_rotate_right(list);
			list_append(ans_list, SA + list->idx);
			list_swap(list, 0);
		}
		else if ((list_gd(list, 0) == sn + 1) && (list_gd(list, 1) == sn))
		{
			list_append(ans_list, SA + list->idx);
			list_swap(list, 0);
		}
		else if ((list_gd(list, 0) == sn + 1) && (list_gd(list, 1) == sn + 2))
		{
			list_append(ans_list, RRA + list->idx);
			list_rotate_right(list);
		}
		else if ((list_gd(list, 0) == sn + 2) && (list_gd(list, 1) == sn))
		{
			list_append(ans_list, RA + list->idx);
			list_rotate_left(list);
		}
		if ((list_gd(list, 0) == sn + 2) && (list_gd(list, 1) == sn + 1))
		{
			list_append(ans_list, SA + list->idx);
			list_swap(list, 0);
			list_append(ans_list, RRA + list->idx);
			list_rotate_right(list);
		}
	}
}

void	divide_list_init(t_list *alist, t_list *blist, t_list *ans_list, int sn)
{
	int	init_alist_len;

	init_alist_len = alist->len;
	sn = list_min(alist);
	if (alist->len <= 6)
	{
		while (alist->len > 3)
		{
			if (list_gd(alist, 0) <= sn + 2)
			{
				list_rotate_left(alist);
				list_append(ans_list, RA + alist->idx);
			}
			else
			{
				list_appendleft(blist, list_gd(alist, 0));
				list_remove_left(alist);
				list_append(ans_list, PB + alist->idx);
			}
		}
	}
	else
	{
		while (alist->len > init_alist_len / 2)
		{
			if (list_gd(alist, 0) < sn + (init_alist_len + 1) / 2)
			{
				list_appendleft(blist, list_gd(alist, 0));
				list_remove_left(alist);
				list_append(ans_list, PB + alist->idx);
			}
			else
			{
				list_rotate_left(alist);
				list_append(ans_list, RA + alist->idx);
			}
		}
	}
}

int	divide_list(t_list *alist, t_list *blist, t_list *ans_list, int sn)
{
	int	init_blist_len;
	int	block_cnt;
	int	move_cnt;

	init_blist_len = blist->len;
	sn = list_min(blist);
	block_cnt = 0;
	move_cnt = 0;
	if (blist->len <= 11)
	{
		if (init_blist_len > 6)
			sn = sn + init_blist_len - 6;
		while (init_blist_len - move_cnt > 3 && move_cnt < 3)
		{
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
				block_cnt += 1;
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
				block_cnt += 1;
			}
		}
	}
	return (block_cnt);
}

void	move_bottom_list(t_list *alist, t_list *blist, t_list *ans_list)
{
	while (list_is_empty(alist) == false)
	{
		list_appendleft(blist, list_gd(alist, 0));
		list_rotate_left(blist);
		list_remove_left(alist);
		list_append(ans_list, PB + alist->idx);
		list_append(ans_list, RA);
	}
}

void	ft_dfs(t_list *alist, t_list *blist, t_list *ans_list,
		t_list *block_list)
{
	int	temp;
	int	block_cnt;

	while (blist->len > 3)
	{
		block_cnt = divide_list(alist, blist, ans_list, 1);
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

void	sort_list_u3_to_bottom(t_list *alist, t_list *blist, t_list *ans_list,
		int num)
{
	int	sn;

	if (num == 1)
	{
		list_rotate_left(alist);
		list_append(ans_list, RA + alist->idx);
		ans_list->bottom += 1;
	}
	else if (num == 2)
	{
		if (list_gd(alist, 0) > list_gd(alist, 1))
		{
			list_append(ans_list, SA + alist->idx);
			list_swap(alist, 0);
		}
		list_rotate_left(alist);
		list_append(ans_list, RA + alist->idx);
		list_rotate_left(alist);
		list_append(ans_list, RA + alist->idx);
		ans_list->bottom += 2;
	}
	else if (num == 3)
	{
		sn = list_min_limit(alist, 3);
		if ((list_gd(alist, 0) == sn) && (list_gd(alist, 1) == sn + 2))
		{
			list_rotate_left(alist);
			list_append(ans_list, RA + alist->idx);
			list_swap(alist, 0);
			list_append(ans_list, SA + alist->idx);
			list_rotate_left(alist);
			list_append(ans_list, RA + alist->idx);
			list_rotate_left(alist);
			list_append(ans_list, RA + alist->idx);
		}
		else if ((list_gd(alist, 0) == sn + 1) && (list_gd(alist, 1) == sn))
		{
			list_append(ans_list, SA + alist->idx);
			list_swap(alist, 0);
			list_append(ans_list, RA + alist->idx);
			list_rotate_left(alist);
			list_append(ans_list, RA + alist->idx);
			list_rotate_left(alist);
			list_append(ans_list, RA + alist->idx);
			list_rotate_left(alist);
		}
		else if ((list_gd(alist, 0) == sn + 1) && (list_gd(alist, 1) == sn + 2))
		{
			list_append(ans_list, PB + alist->idx);
			list_append(ans_list, SA + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, PB + blist->idx);
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_remove_left(alist);
			list_remove_left(alist);
			list_remove_left(alist);
			list_append(alist, sn);
			list_append(alist, sn + 1);
			list_append(alist, sn + 2);
		}
		else if ((list_gd(alist, 0) == sn + 2) && (list_gd(alist, 1) == sn))
		{
			list_append(ans_list, PB + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, PB + blist->idx);
			list_append(ans_list, RA + alist->idx);
			list_remove_left(alist);
			list_remove_left(alist);
			list_remove_left(alist);
			list_append(alist, sn);
			list_append(alist, sn + 1);
			list_append(alist, sn + 2);
		}
		else if ((list_gd(alist, 0) == sn + 2) && (list_gd(alist, 1) == sn + 1))
		{
			list_append(ans_list, PB + alist->idx);
			list_append(ans_list, SA + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, PB + blist->idx);
			list_append(ans_list, RA + alist->idx);
			list_remove_left(alist);
			list_remove_left(alist);
			list_remove_left(alist);
			list_append(alist, sn);
			list_append(alist, sn + 1);
			list_append(alist, sn + 2);
		}
		else
		{
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_append(ans_list, RA + alist->idx);
			list_rotate_left(alist);
			list_rotate_left(alist);
			list_rotate_left(alist);
		}
		ans_list->bottom += 3;
	}
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
