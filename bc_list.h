/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:33:46 by karai             #+#    #+#             */
/*   Updated: 2024/11/19 21:52:02 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BC_LIST_H
# define BC_LIST_H

# include <stdbool.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;
typedef struct s_list
{
	t_node			*head;
}					t_list;

bool				list_is_empty(t_list *list);
void				list_append(t_list *list, int num);
void				list_print(t_list *list);
void				list_appendleft(t_list *list, int num);
void				list_rotate_right(t_list *list);
void				list_rotate_left(t_list *list);
void				list_remove_left(t_list *list);

#endif
