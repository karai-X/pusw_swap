/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:29:25 by karai             #+#    #+#             */
/*   Updated: 2024/11/29 00:25:56 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

t_list	*ft_solve(t_list *alist, t_list *blist, t_list *ans_list,
		t_list *block_list)
{
	int	len;

	len = alist->len;
	if (len < 4)
		sort_list_u3(alist, ans_list);
	else if (len < 7)
	{
		divide_list_init(alist, blist, ans_list, 1);
		sort_list_u3(alist, ans_list);
		sort_list_u3(blist, ans_list);
		move_bottom_list(blist, alist, ans_list);
	}
	else
	{
		divide_list_init(alist, blist, ans_list, 1);
		list_appendleft(block_list, len / 2);
		list_appendleft(block_list, 0);
		while (list_is_empty(block_list) == false)
		{
			if (list_gd(block_list, 0) <= 3 && list_gd(block_list, 0) >= 1)
			{
				sort_list_u3_to_bottom(alist, blist, ans_list,
					list_gd(block_list, 0));
				list_remove_left(block_list);
			}
			else
			{
				list_move(alist, blist, ans_list, list_gd(block_list, 0));
				list_remove_left(block_list);
				ft_dfs(alist, blist, ans_list, block_list);
				sort_list_u3_to_other(alist, blist, ans_list);
			}
		}
	}
	return (ans_list);
}