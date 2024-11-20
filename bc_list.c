/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:03:34 by karai             #+#    #+#             */
/*   Updated: 2024/11/20 22:27:38 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

bool	list_is_empty(t_list *list)
{
	if (list->head == NULL)
		return (true);
	else
		return (false);
}

void	list_append(t_list *list, int num)
{
	t_node	*new_node;
	t_node	*tmp_ptr;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = num;
	if (list_is_empty(list) == true)
	{
		list->head = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		tmp_ptr = list->head->prev;
		list->head->prev = new_node;
		new_node->next = list->head;
		new_node->prev = tmp_ptr;
		tmp_ptr->next = new_node;
	}
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

void	list_appendleft(t_list *list, int num)
{
	list_append(list, num);
	list_rotate_right(list);
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

void	list_remove_left(t_list *list)
{
	t_node	*tmp_ptr;

	if (list_is_empty(list) == false)
	{
		list->head->next->prev = list->head->prev;
		list->head->prev->next = list->head->next;
		tmp_ptr = list->head;
		if (list->head == list->head->next)
			list->head = NULL;
		else
			list->head = list->head->next;
		free(tmp_ptr);
	}
}

int	list_get_data(t_list *list, int idx)
{
	int		i;
	t_node	*tmp_ptr;

	if (list_is_empty(list))
		return (-1);
	else
	{
		i = 0;
		tmp_ptr = list->head;
		while (i != idx)
		{
			tmp_ptr = tmp_ptr->next;
			i += 1;
		}
		return (tmp_ptr->data);
	}
}

// int	list_search(t_list *list, int search_num)
// {
// 	int	i;

// 	i = 0;
// 	if (list_is_empty(list))
// 		return ;
// 	else
// 	{
// 		if (list)
// 	}

// }

// void	list_swap(t_list *list)
// {
// 	t_node	*tmp_ptr;
// }