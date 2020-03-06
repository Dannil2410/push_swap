/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:50:37 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 18:29:44 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	working_to_three(t_sort *sort)
{
	if (sorting_good(sort->a))
		return ;
	if (sort->a->elem > sort->a->next->next->elem &&
			sort->a->elem < sort->a->next->elem)
		check_and_work("rra", sort, 1);
	else if (sort->a->elem > sort->a->next->next->elem &&
			sort->a->next->elem < sort->a->next->next->elem)
		check_and_work("ra", sort, 1);
	else
		check_and_work("sa", sort, 1);
	working_to_three(sort);
}

void	working_to_five(t_sort *sort)
{
	check_and_work("pb", sort, 1);
	check_and_work("pb", sort, 1);
	working_to_three(sort);
	if (working_to_five_htwo(sort->a, sort->b, sort) == 0)
		return ;
	working_to_five_help(sort);
	if (sort->b && sort->b->elem < sort->a->elem &&
			sort->b->elem > last_el_of_l(sort->a)->elem)
		check_and_work("pa", sort, 1);
	else if (sort->b && sort->b->elem < sort->a->elem &&
			sort->b->elem < last_el_of_l(sort->a)->elem)
	{
		while (sort->b->elem < last_el_of_l(sort->a)->elem)
			check_and_work("rra", sort, 1);
		check_and_work("pa", sort, 1);
	}
	else if (sort->b && sort->b->elem > sort->a->elem)
	{
		if (sort->b->elem < last_el_of_l(sort->a)->elem)
			while (sort->b->elem > sort->a->elem)
				check_and_work("rra", sort, 1);
		check_and_work("pa", sort, 1);
		check_and_work("ra", sort, 1);
	}
	sorting(sort);
}

void	working_with_other(t_sort *sort)
{
	search_max_sort(sort);
	while (sort->a && sort->a->i != sort->max_sort->i)
		check_and_work("pb", sort, 1);
	return_a(sort);
	sort->len_a = nums_el_of_mas(sort->a);
	sorting(sort);
}

int		main(int ac, char **av)
{
	t_sort *sort;

	if ((sort = create_stack_sort(ac, av)) == NULL ||
			sort->a == NULL)
	{
		sort_del(sort);
		return (0);
	}
	if (sort->len_a <= 3)
		working_to_three(sort);
	else if (sort->len_a <= 5)
		working_to_five(sort);
	else
		working_with_other(sort);
	sort_del(sort);
	return (0);
}
