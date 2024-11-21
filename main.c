/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:26 by karai             #+#    #+#             */
/*   Updated: 2024/11/21 23:39:05 by karai            ###   ########.fr       */
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
	list_print(alist);
	printf("\n");
	printf("argc - 1: %d\n", argc - 1);
	if ((argc - 1) < 4)
	{
		sort_list_u3(alist, ans_list);
		list_print(alist);
		printf("\n");
		list_print(ans_list);
	}
	printf("len: %d\n", alist->len);
	if ((argc - 1) < 7)
	{
		divide_list(alist, blist, ans_list, 1);
		sort_list_u3(alist, ans_list);
		sort_list_u3(blist, ans_list);
	}
	printf("alist\n");
	list_print(alist);
	printf("blist\n");
	list_print(blist);
	printf("ans_list\n");
	list_print(ans_list);
}
