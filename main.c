/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:26 by karai             #+#    #+#             */
/*   Updated: 2024/11/26 22:14:06 by karai            ###   ########.fr       */
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
	int		i;
	int		*array;
	t_list	alist[1];
	t_list	blist[1];
	t_list	ans_list[1];
	t_list	block_list[1];

	array = malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		i += 1;
	}
	if (ft_comp_cord(array, argc - 1) == NULL)
	{
		free(array);
		return (1);
	}
	alist->head = NULL;
	alist->idx = 0;
	alist->len = 0;
	blist->head = NULL;
	blist->idx = 1;
	blist->len = 0;
	ans_list->bottom = 0;
	i = 0;
	while (i < argc - 1)
	{
		list_append(alist, array[i]);
		i += 1;
	}
	if ((argc - 1) < 4)
	{
		sort_list_u3(alist, ans_list);
		list_print(alist);
		printf("\n");
		list_print(ans_list);
	}
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
			// printf("%d\n",ans_list->bottom);
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
				// move_bottom_list(blist, alist, ans_list);
			}
		}
	}
	// printf("alist\n");
	// list_print(alist);
	print_ans(ans_list);
	printf("ans_list len: %d\n", ans_list->len);
}
