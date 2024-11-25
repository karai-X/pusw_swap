/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:12:04 by karai             #+#    #+#             */
/*   Updated: 2024/11/25 23:29:44 by karai            ###   ########.fr       */
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

void	divide_list(t_list *alist, t_list *blist, t_list *ans_list, int sn)
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
			if (list_gd(alist, 0) < sn + init_alist_len / 2)
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

void	ft_dfs(t_list *blist, t_list *alist, t_list *ans_list,
		t_list *block_list)
{
	int	temp;

	while (blist->len > 3)
	{
		temp = blist->len;
		divide_list(blist, alist, ans_list, 1);
		list_appendleft(block_list, temp - blist->len);
	}
}

void	list_move(t_list *alist, t_list *blist, t_list *ans_list, int move_num)
{
	int	i;

	i = 0;
	while (i < move_num)
	{
		list_append(ans_list, PB + alist->idx);
		list_appendleft(blist, list_gd(alist, 0));
		list_remove_left(alist);
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
	}
}
