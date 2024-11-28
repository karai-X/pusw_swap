/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:26 by karai             #+#    #+#             */
/*   Updated: 2024/11/28 22:10:10 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	print_ans_part(int num)
{
	if (num == SA)
		printf("sa\n");
	if (num == SB)
		printf("sb\n");
	if (num == SS)
		printf("ss\n");
	if (num == PB)
		printf("pb\n");
	if (num == PA)
		printf("pa\n");
	if (num == RA)
		printf("ra\n");
	if (num == RB)
		printf("rb\n");
	if (num == RR)
		printf("rr\n");
	if (num == RRA)
		printf("rra\n");
	if (num == RRB)
		printf("rrb\n");
	if (num == RRR)
		printf("rrr\n");
}

void	print_ans(t_list *ans_list)
{
	t_node	*tmp_ptr;

	tmp_ptr = ans_list->head;
	print_ans_part(tmp_ptr->data);
	tmp_ptr = tmp_ptr->next;
	while (tmp_ptr != ans_list->head)
	{
		print_ans_part(tmp_ptr->data);
		tmp_ptr = tmp_ptr->next;
	}
}

int	main(int argc, char *argv[])
{
	int		*array;
	t_list	alist[1];
	t_list	blist[1];
	t_list	ans_list[1];
	t_list	block_list[1];

	array = ft_comp_cord_main(argc, argv);
	if (array == NULL)
		return (1);
	list_initialize(alist, blist, ans_list);
	if (list_initial_make(alist, array, argc) == NULL)
		return (1);
	if ((argc - 1) < 4)
		sort_list_u3(alist, ans_list);
	if ((argc - 1) < 7)
	{
		divide_list_init(alist, blist, ans_list, 1);
		sort_list_u3(alist, ans_list);
		sort_list_u3(blist, ans_list);
		move_bottom_list(blist, alist, ans_list);
	}
	if ((argc - 1) >= 7)
	{
		argc = argc - 1;
		divide_list_init(alist, blist, ans_list, 1);
		list_appendleft(block_list, argc / 2);
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
	ft_integrate(ans_list);
	print_ans(ans_list);
	// free
}
