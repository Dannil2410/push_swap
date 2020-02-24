/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:50:37 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/24 15:52:51 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "stdio.h"

void	ft_working_to_three(t_sort *sort)
{
	if (ft_sorting_good(sort->a))
		return ;
	if (sort->a->elem > sort->a->next->next->elem &&
			sort->a->elem < sort->a->next->elem)
		ft_check_and_work("rra", sort, 1);
	else if (sort->a->elem > sort->a->next->next->elem &&
			sort->a->next->elem < sort->a->next->next->elem)
		ft_check_and_work("ra", sort, 1);
	else
		ft_check_and_work("sa", sort, 1);
	ft_working_to_three(sort);
}

void	ft_working_to_five(t_sort *sort)
{
	ft_check_and_work("pb", sort, 1);
	ft_check_and_work("pb", sort, 1);
	ft_working_to_three(sort);
	if (ft_working_to_five_htwo(sort->a, sort->b, sort) == 0)
		return ;
	ft_working_to_five_help(sort);
	if (sort->b && sort->b->elem < sort->a->elem &&
			sort->b->elem > ft_last_el_of_l(sort->a)->elem)
		ft_check_and_work("pa", sort, 1);
	else if (sort->b && sort->b->elem < sort->a->elem &&
			sort->b->elem < ft_last_el_of_l(sort->a)->elem)
	{
		while (sort->b->elem < ft_last_el_of_l(sort->a)->elem)
			ft_check_and_work("rra", sort, 1);
		ft_check_and_work("pa", sort, 1);
	}
	else if (sort->b && sort->b->elem > sort->a->elem)
	{
		while (ft_sorting_good(sort->a) == 0)
			ft_check_and_work("ra", sort, 1);
		ft_check_and_work("pa", sort, 1);
		ft_check_and_work("rra", sort, 1);
	}
	while (ft_sorting_good(sort->a) == 0)
		ft_check_and_work("ra", sort, 1);
}

int		main(int ac, char **av)
{
	t_sort *sort;

	if ((sort = ft_create_stack_sort(ac, av)) == NULL)
		ft_error(sort);
	if (sort->len_a <= 3)
		ft_working_to_three(sort);
	else if (sort->len_a <= 5)
		ft_working_to_five(sort);
	else if (sort->len_a <= 100)
		ft_working_to_hundred(sort);
	ft_sort_del(sort);
	return (0);
}
