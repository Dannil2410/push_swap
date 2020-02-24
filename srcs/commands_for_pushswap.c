/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_pushswap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:53 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/24 15:52:48 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_five_help(t_sort *sort)
{
	if (sort->b->elem < sort->b->next->elem)
		ft_check_and_work("sb", sort, 1);
	ft_check_and_work("pa", sort, 1);
	ft_check_and_work("sa", sort, 1);
}

void	ft_working_to_five_help(t_sort *sort)
{
	if (sort->b && sort->b->elem > sort->a->elem &&
			sort->b->elem < sort->a->next->elem)
	{
		(sort->b->next && sort->b->next->elem > sort->a->elem &&
		sort->b->next->elem < sort->a->next->elem ? ft_five_help(sort) : 0);
		ft_check_and_work("pa", sort, 1);
		ft_check_and_work("sa", sort, 1);
	}
	else if (sort->b && sort->b->elem > sort->a->elem &&
			sort->b->elem > sort->a->next->elem)
	{
		if (sort->b->next && sort->b->elem < sort->b->next->elem)
			ft_check_and_work("sb", sort, 1);
		if (sort->b->elem > ft_last_el_of_l(sort->a)->elem)
			ft_check_and_work("pa", sort, 1);
		else
		{
			while (sort->b->elem > sort->a->elem ||
					sort->b->elem < ft_last_el_of_l(sort->a)->elem)
				ft_check_and_work("rra", sort, 1);
			ft_check_and_work("pa", sort, 1);
		}
	}
}

int		ft_working_to_five_htwo(t_mas *a, t_mas *b, t_sort *sort)
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
				ft_check_and_work("sb", sort, 1);
			ft_check_and_work("pa", sort, 1);
			ft_check_and_work("pa", sort, 1);
			return (0);
		}
		if (b->elem > b->next->elem)
			ft_check_and_work("sb", sort, 1);
		ft_check_and_work("pa", sort, 1);
	}
	return (1);
}
