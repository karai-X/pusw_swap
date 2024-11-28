/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_u3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:52:52 by karai             #+#    #+#             */
/*   Updated: 2024/11/29 00:57:09 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	sort_list_u3_part(t_list *list, t_list *ans_list, int sn)
{
	if ((list_gd(list, 0) == sn) && (list_gd(list, 1) == sn + 2))
	{
		list_append(ans_list, RRA + list->idx);
		list_rotate_right(list);
	}
	if ((list_gd(list, 0) == sn + 1) && (list_gd(list, 1) == sn))
	{
		list_append(ans_list, SA + list->idx);
		list_swap(list, 0);
	}
	if ((list_gd(list, 0) == sn + 2) && (list_gd(list, 1) == sn + 1))
	{
		list_append(ans_list, SA + list->idx);
		list_swap(list, 0);
	}
	if ((list_gd(list, 0) == sn + 1) && (list_gd(list, 1) == sn + 2))
	{
		list_append(ans_list, RRA + list->idx);
		list_rotate_right(list);
	}
	if ((list_gd(list, 0) == sn + 2) && (list_gd(list, 1) == sn))
	{
		list_append(ans_list, RA + list->idx);
		list_rotate_left(list);
	}
}

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
		sort_list_u3_part(list, ans_list, sn);
	}
}
