/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:26 by karai             #+#    #+#             */
/*   Updated: 2024/11/30 07:56:55 by karai            ###   ########.fr       */
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
	if (ft_solve(alist, blist, ans_list, block_list) == NULL)
	{
		free(array);
		return (1);
	}
	ft_integrate(ans_list);
	print_ans(ans_list);
	// free
}
