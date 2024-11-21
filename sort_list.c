/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:12:04 by karai             #+#    #+#             */
/*   Updated: 2024/11/21 23:37:51 by karai            ###   ########.fr       */
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
	printf("sn: %d\n",sn);
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
			list_rotate_left(list);
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

void	divide_list(t_list *alist, t_list *blist, t_list *ans_list, int sn)
{
	int	und_remain;

	und_remain = sn + 2;
	if (alist->len <= 6)
	{
		while (alist->len > 3)
		{
			if (list_gd(alist, 0) <= und_remain)
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
