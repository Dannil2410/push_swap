/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:17:33 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/17 14:08:04 by tstripeb         ###   ########.fr       */
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
	struct s_mas	*next;	
}					t_mas;


typedef struct		s_sort
{
	t_mas			*a;
	t_mas			*b;
	int				nums;
	int				len_a;
	int				len_b;
	int				flag_v;
}					t_sort;

t_sort				*ft_create_stack_sort(int ac, char **av);
void				ft_create_list_masa(t_sort *sort,int ac, char **av);
int					ft_valid_val(int value, char *str);
int					ft_double_val(t_mas *a, int value);
t_mas				*ft_create_masi(t_mas **tmp, int number);
t_mas				*ft_one_elem_of_l(int number);
int					ft_nums_el_of_mas(t_mas *tmp);
t_mas				*ft_last_el_of_l(t_mas *temp);
int					ft_error_message(int i);
void				ft_read_commands(t_sort *sort);
void					ft_check_and_work(char *command, t_sort *sort);
void				ft_conclusionab(t_mas *a, t_mas *b);
void				ft_commands_s(t_mas *a, t_mas *b, int flag);
void				ft_commands_p(t_mas **first, t_mas **second);
void				ft_commands_r(t_mas **mas);
void				ft_commands_rr(t_mas **mas);
void				ft_commands_rr_rrr(t_mas **a, t_mas **b, int flag);
int					ft_sorting_good(t_mas *a);

#endif
