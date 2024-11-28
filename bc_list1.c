/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:53:16 by karai             #+#    #+#             */
/*   Updated: 2024/11/28 22:07:52 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	list_initialize(t_list *alist, t_list *blist, t_list *ans_list)
{
	alist->head = NULL;
	alist->idx = 0;
	alist->len = 0;
	blist->head = NULL;
	blist->idx = 1;
	blist->len = 0;
	ans_list->bottom = 0;
}

t_list	*list_initial_make(t_list *alist, int *array, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (list_append(alist, array[i]) == NULL)
		{
			//processing for free alist and array should be written here
			return (NULL);
		}
		i += 1;
	}
	return (alist);
}

bool	list_is_empty(t_list *list)
{
	if (list->head == NULL)
		return (true);
	else
		return (false);
}

void	list_print(t_list *list)
{
	t_node	*tmp_ptr;

	if (list_is_empty(list) == true)
		return ;
	else
	{
		tmp_ptr = list->head;
		printf("%d\n", tmp_ptr->data);
		tmp_ptr = tmp_ptr->next;
		while (tmp_ptr != list->head)
		{
			printf("%d\n", tmp_ptr->data);
			tmp_ptr = tmp_ptr->next;
		}
	}
}

void	list_rotate_right(t_list *list)
{
	if (list_is_empty(list) == false)
		list->head = list->head->prev;
}

void	list_rotate_left(t_list *list)
{
	if (list_is_empty(list) == false)
		list->head = list->head->next;
}
