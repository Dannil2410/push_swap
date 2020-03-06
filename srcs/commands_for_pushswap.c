/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_pushswap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:53 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 18:30:21 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_index(t_mas *mas)
{
	int i;

	i = 0;
	while (mas)
	{
		mas->i = i;
		mas = mas->next;
		i++;
	}
}

void	sorting(t_sort *sort)
{
	int		elem;
	int		i;
	t_mas	*mas;

	mas = sort->a;
	elem = mas->elem;
	i = mas->i;
	ft_index(mas);
	while (mas->next)
	{
		mas = mas->next;
		if (mas->elem < elem)
		{
			elem = mas->elem;
			i = mas->i;
		}
	}
	while (sorting_good(sort->a) == 0)
		check_and_work((i <= sort->len_a / 2 ? "ra" : "rra"), sort, 1);
}

void	five_help(t_sort *sort)
{
	if (sort->b->elem < sort->b->next->elem)
		check_and_work("sb", sort, 1);
	check_and_work("pa", sort, 1);
	check_and_work("sa", sort, 1);
}

void	working_to_five_help(t_sort *sort)
{
	if (sort->b && sort->b->elem > sort->a->elem &&
			sort->b->elem < sort->a->next->elem)
	{
		(sort->b->next && sort->b->next->elem > sort->a->elem &&
		sort->b->next->elem < sort->a->next->elem ? five_help(sort) : 0);
		check_and_work("pa", sort, 1);
		check_and_work("sa", sort, 1);
	}
	else if (sort->b && sort->b->elem > sort->a->elem &&
			sort->b->elem > sort->a->next->elem)
	{
		if (sort->b->next && sort->b->elem < sort->b->next->elem)
			check_and_work("sb", sort, 1);
		if (sort->b->elem > last_el_of_l(sort->a)->elem)
			check_and_work("pa", sort, 1);
		else
		{
			while (sort->b->elem > sort->a->elem ||
					sort->b->elem < last_el_of_l(sort->a)->elem)
				check_and_work("rra", sort, 1);
			check_and_work("pa", sort, 1);
		}
	}
}

int		working_to_five_htwo(t_mas *a, t_mas *b, t_sort *sort)
{
	int		flag;

	flag = 0;
	if (b->elem < a->elem || b->next->elem < a->elem)
	{
		flag++;
		if (b->elem < a->elem && b->next->elem < a->elem)
			flag++;
	}
	if (flag > 0)
	{
		if (flag > 1)
		{
			if (b->elem < b->next->elem)
				check_and_work("sb", sort, 1);
			check_and_work("pa", sort, 1);
			check_and_work("pa", sort, 1);
			return (0);
		}
		if (b->elem > b->next->elem)
			check_and_work("sb", sort, 1);
		check_and_work("pa", sort, 1);
	}
	return (1);
}
