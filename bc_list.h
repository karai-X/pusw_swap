/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:33:46 by karai             #+#    #+#             */
/*   Updated: 2024/11/28 22:11:29 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BC_LIST_H
# define BC_LIST_H

# include <limits.h>
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
	int				bottom;
}					t_list;

bool				list_is_empty(t_list *list);
t_list				*list_append(t_list *list, int num);
void				list_print(t_list *list);
t_list				*list_appendleft(t_list *list, int num);
void				list_rotate_right(t_list *list);
void				list_rotate_left(t_list *list);
void				list_remove_left(t_list *list);
int					list_gd(t_list *list, int idx);
void				list_swap(t_list *list, int idx);
int					list_last(t_list *list);
void				list_remove_right(t_list *list);

void				sort_list_u3(t_list *list, t_list *ans_list);
int					divide_list(t_list *alist, t_list *blist, t_list *ans_list,
						int sn);
int					list_min(t_list *list);
void				move_bottom_list(t_list *alist, t_list *blist,
						t_list *ans_list);
void				ft_dfs(t_list *blist, t_list *alist, t_list *ans_list,
						t_list *block_list);
void				list_move(t_list *alist, t_list *blist, t_list *ans_list,
						int move_num);
void				divide_list_init(t_list *alist, t_list *blist,
						t_list *ans_list, int sn);
void				sort_list_u3_to_bottom(t_list *alist, t_list *blist,
						t_list *ans_list, int num);
int					list_min_limit(t_list *list, int num);
void				sort_list_u3_to_other(t_list *alist, t_list *blist,
						t_list *ans_list);
void				list_initialize(t_list *alist, t_list *blist,
						t_list *ans_list);
t_list				*list_initial_make(t_list *alist, int *array, int argc);

void				integrate_pb_pa(t_list *list);
void				integrate_rb_ra(t_list *list);
void				ft_integrate(t_list *ans_list);
void				integarate_pb_ra_pa_part(t_node *tmp_ptr, int *cnt);
void				integarate_pb_ra_pa(t_list *list);
void				integrate_sb_pa_ra_pa_ra_part(t_node *tmp_ptr);
void				integrate_sb_pa_ra_pa_ra(t_list *list);
void				integarate_pb_pb_rb_pa_part(t_node *tmp_ptr, int *cnt,
						t_list *ans_list);
void				integarate_pb_pb_rb_pa(t_list *list);
void				integarate_pa_pa_ra_pb_part(t_node *tmp_ptr, int *cnt,
						t_list *ans_list);
void				integarate_pa_pa_ra_pb(t_list *list);

#endif
