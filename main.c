/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:26 by karai             #+#    #+#             */
/*   Updated: 2024/11/25 23:31:09 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

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
	blist->idx = 0;
	blist->len = 0;
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
			// printf("num: %d\n", list_gd(block_list, 0));
			// if (list_gd(block_list, 0) <= 3)
			// {
			// 	printf("dfasg\n");
			// 	sort_list_u3_to_bottom(alist, blist, ans_list,
			// 		list_gd(block_list, 0));
			// 	list_remove_left(block_list);
			// }
			// else
			// {
				list_move(alist, blist, ans_list, list_gd(block_list, 0));
				list_remove_left(block_list);
				ft_dfs(blist, alist, ans_list, block_list);
				sort_list_u3(blist, ans_list);
				move_bottom_list(blist, alist, ans_list);
			// }
			// printf("alist\n");
			// list_print(alist);
		}
	}
	printf("alist\n");
	list_print(alist);
	printf("ans_list len: %d\n", ans_list->len);
	// list_print(ans_list);
}
