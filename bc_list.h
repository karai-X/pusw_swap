/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:33:46 by karai             #+#    #+#             */
/*   Updated: 2024/11/23 00:09:49 by karai            ###   ########.fr       */
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
	int				idx;
	int				len;
}					t_list;

bool				list_is_empty(t_list *list);
void				list_append(t_list *list, int num);
void				list_print(t_list *list);
void				list_appendleft(t_list *list, int num);
void				list_rotate_right(t_list *list);
void				list_rotate_left(t_list *list);
void				list_remove_left(t_list *list);
int					list_gd(t_list *list, int idx);
void				list_swap(t_list *list, int idx);

void				sort_list_u3(t_list *list, t_list *ans_list);
void				divide_list(t_list *alist, t_list *blist, t_list *ans_list,
						int sn);
int					list_min(t_list *list);
void				move_bottom_list(t_list *alist, t_list *blist,
						t_list *ans_list);

#endif
