/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_u3_to_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 21:53:03 by karai             #+#    #+#             */
/*   Updated: 2024/11/29 22:35:55 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*sort_list_u3_to_bottom_part1(t_list *alist, t_list *ans_list)
{
	if (list_gd(alist, 0) > list_gd(alist, 1))
	{
		if (list_swap_ans(alist, ans_list) == NULL)
			return (NULL);
	}
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	ans_list->bottom += 2;
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part2(t_list *alist, t_list *blist,
		t_list *ans_list)
{
	int	sn;

	sn = list_min_limit(alist, 3);
	if ((list_gd(alist, 0) == sn) && (list_gd(alist, 1) == sn + 2))
	{
		if (sort_list_u3_to_bottom_part3(alist, ans_list) == NULL)
			return (NULL);
	}
	else if ((list_gd(alist, 0) == sn + 1) && (list_gd(alist, 1) == sn))
	{
		if (sort_list_u3_to_bottom_part4(alist, ans_list)==NULL)
			return (NULL);
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
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part3(t_list *alist, t_list *ans_list)
{
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_swap_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom_part4(t_list *alist, t_list *ans_list)
{
	if (list_swap_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	if (list_rotate_left_ans(alist, ans_list) == NULL)
		return (NULL);
	return (ans_list);
}

t_list	*sort_list_u3_to_bottom(t_list *alist, t_list *blist, t_list *ans_list,
		int num)
{
	int	sn;

	if (num == 1)
	{
		if (list_rotate_left_ans(alist, ans_list) == NULL)
			return (NULL);
		ans_list->bottom += 1;
	}
	else if (num == 2)
	{
		if (sort_list_u3_to_bottom_part1(alist, ans_list) == NULL)
			return (NULL);
	}
	else if (num == 3)
	{
		if (sort_list_u3_to_bottom_part2(alist, blist, ans_list) == NULL)
			return (NULL);
	}
	return (ans_list);
}
