/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:12:26 by karai             #+#    #+#             */
/*   Updated: 2024/11/19 22:10:42 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		*array;
	t_list	list[0];

	array = malloc(sizeof(int) * (argc - 1));
	i = 1;
	while (i < argc)
	{
		array[i - 1] = ft_atoi(argv[i]);
		i += 1;
	}
	i = 0;
	while (i < argc - 1)
	{
		printf("%d\n", array[i]);
		i += 1;
	}
	ft_comp_cord(array, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		printf("%d\n", array[i]);
		i += 1;
	}
	printf("\nlist zone\n");
	list->head = NULL;
	i = 0;
	while (i < argc - 1)
	{
		list_append(list, array[i]);
		i += 1;
	}
	list_print(list);
	printf("\nlist zone\n");
	list_appendleft(list, 123);
	list_append(list, 999);
	list_rotate_left(list);
	list_print(list);
	list_remove_left(list);
	printf("%p %p %p\n",list->head, list->head->next, list->head->prev);
	list_remove_left(list);
	printf("%p\n",list->head);
	printf("\nlist zone\n");
	list_print(list);
	free(array);
}
