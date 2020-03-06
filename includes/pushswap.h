/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:17:33 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 17:48:01 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "unistd.h"
# include "stdlib.h"
# include "stdarg.h"
# include "../libft/libft.h"

typedef struct		s_mas
{
	int				elem;
	int				i;
	int				sort;
	struct s_mas	*next;
}					t_mas;

typedef struct		s_sort
{
	t_mas			*a;
	t_mas			*b;
	t_mas			*max_sort;
	int				nums;
	int				len_a;
	int				len_b;
	int				tmp_a;
	int				tmp_b;
	int				t_place;
	int				need_a;
	int				need_b;
	int				n_place;
	int				flag_v;
}					t_sort;

t_sort				*create_stack_sort(int ac, char **av);
void				create_list_masa(t_sort *sort, int ac, char **av);
int					valid_val(int value, char *str);
int					double_val(t_mas *a, int value);
t_mas				*create_masi(t_mas **tmp, int number);
t_mas				*one_elem_of_l(int number);
int					nums_el_of_mas(t_mas *tmp);
t_mas				*last_el_of_l(t_mas *temp);
void				error(t_sort *sort);
void				read_commands(t_sort *sort);
void				check_and_work(char *command, t_sort *sort, int flag);
void				conclusionab(t_mas *a, t_mas *b);
void				commands_s(t_mas *a, t_mas *b, int flag);
void				commands_p(t_mas **first, t_mas **second);
void				commands_r(t_mas **mas);
void				commands_rr(t_mas **mas);
void				commands_rr_rrr(t_mas **a, t_mas **b, int flag);
int					sorting_good(t_mas *a);
void				sort_del(t_sort *sort);
void				mas_del(t_mas *mas);
char				**freetime(char **av, int nums, int flag_v);
void				working_to_three(t_sort *sort);
void				working_to_five(t_sort *sort);
void				working_to_five_help(t_sort *sort);
int					working_to_five_htwo(t_mas *a, t_mas *b, t_sort *sort);
void				five_help(t_sort *sort);
void				putcommand(char *command);
void				ft_index(t_mas *mas);
void				sorting(t_sort *sort);
void				working_with_other(t_sort *sort);
void				search_max_sort(t_sort *sort);
t_mas				*max_sort(t_mas *a, t_sort *s, t_mas *mas);
void				return_a(t_sort *sort);
void				neednbrofcmds(t_sort *sort, int flag);
int					mincmdspastone(t_sort *sort, t_mas *ma, int b_el, int b_i);
int					mincmdspastwo(t_sort *sort, int b_el, int b_i);
void				paste_to_a(t_sort *sort);

#endif
