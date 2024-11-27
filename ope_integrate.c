/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_integrate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:00:01 by karai             #+#    #+#             */
/*   Updated: 2024/11/27 22:55:03 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bc_list.h"
#include "libft.h"
#include "push_swap.h"

void	integarate_pb_ra_pa(t_list *list)
{
	t_node	*tmp_ptr;
	t_node	*delete_node;
	int		cnt;

	cnt = 0;
	if (list_is_empty(list) == true)
		return ;
	else
	{
		tmp_ptr = list->head->next;
		while (tmp_ptr != list->head)
		{
			if (cnt == 0 && tmp_ptr->data == PB)
				cnt = 1;
			else if (cnt == 1 && tmp_ptr->data == RA)
				cnt = 2;
			else if (cnt == 2 && tmp_ptr->data == PA)
			{
				cnt = 0;
				tmp_ptr->prev->prev->data = SA;
				tmp_ptr->prev->data = RA;
				tmp_ptr->prev->next = tmp_ptr->next;
				tmp_ptr->next->prev = tmp_ptr->prev;
				delete_node = tmp_ptr;
				tmp_ptr = tmp_ptr->prev;
				free(delete_node);
				list->len -= 1;
			}
			else
				cnt = 0;
			tmp_ptr = tmp_ptr->next;
		}
	}
}

void	integrate_pb_pa(t_list *list)
{
	t_node	*tmp_ptr;
	t_node	*delete_node1;
	t_node	*delete_node2;

	if (list_is_empty(list) == true || list->len <= 3)
		return ;
	else
	{
		tmp_ptr = list->head->next->next;
		while (tmp_ptr != list->head)
		{
			if ((tmp_ptr->prev->data == PB && tmp_ptr->data == PA)
				|| (tmp_ptr->prev->data == PA && tmp_ptr->data == PB))
			{
				delete_node1 = tmp_ptr->prev;
				delete_node2 = tmp_ptr;
				tmp_ptr->prev->prev->next = tmp_ptr->next;
				tmp_ptr->next->prev = tmp_ptr->prev->prev;
				free(delete_node1);
				free(delete_node2);
				list->len -= 2;
			}
			tmp_ptr = tmp_ptr->next;
		}
	}
}

void	integrate_rb_ra(t_list *list)
{
	t_node	*tmp_ptr;
	t_node	*delete_node;

	if (list_is_empty(list) == true || list->len <= 3)
		return ;
	else
	{
		tmp_ptr = list->head->next->next;
		while (tmp_ptr != list->head)
		{
			if ((tmp_ptr->prev->data == RA && tmp_ptr->data == RB)
				|| (tmp_ptr->prev->data == RB && tmp_ptr->data == RA))
			{
				delete_node = tmp_ptr;
				tmp_ptr->prev->next = tmp_ptr->next;
				tmp_ptr->next->prev = tmp_ptr->prev;
				tmp_ptr->prev->data = RR;
				tmp_ptr = tmp_ptr->prev;
				free(delete_node);
				list->len -= 1;
			}
			tmp_ptr = tmp_ptr->next;
		}
	}
}
