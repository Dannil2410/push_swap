/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:08:42 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/18 17:38:52 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_working_finish(t_sort *sort)
{
	if (ft_comparefirsttwoelem(sort->b))
	{
		ft_check_and_work("sb", sort);
		ft_putstr("sb\n");
	}
}

void	ft_working_continue(t_sort *sort)
{
	int flag;

	flag = 0;
	if ((flag = ft_increasewithsecond(sort->a)) != 0)
	{
		if (flag == 1)
		{
			ft_check_and_work("ra", sort);
			ft_putstr("ra\n");
			continue;
		}
	}
	if (ft_comparefirsttwoelem(sort->a))
	{
		ft_check_and_work("sa", sort);
		ft_putstr("sa\n");
	}
	else
	{
		ft_check_and_work("pb", sort);
		sort->len_a--;
		if (sort->b->next)
			ft_working_finish(sort);
	}
}

void	ft_working(t_sort *sort)
{
	int flag;

	flag = 0;
	while ((ft_sorting_good(sort->a) == 0 && sort->len_a == sort->nums)
		 || (ft_sorting_good(sort->a) == 0 && sort->len_a != sort->nums))
	{
		if ((flag = ft_increasetolast(sort->a)) != 0)
		{
			if (flag == 1)
			{
				ft_check_and_work("rra", sort);
				ft_putstr("rra\n");
				continue;
			}
		}
		ft_working_continue(sort);
	}
	if (ft_sorting_good(sort->a) == 1 && sort->len_a != sort->nums)
	{
		while (sort->len_a != sort->nums)
		//функция возвращения элементов из массива b в массив a
	}
}

int		main(int ac, char **av)
{
	t_sort  *sort;

	if ((sort = ft_create_stack_sort(ac, av)) == NULL)
		ft_error(sort);
	ft_working(sort);
	ft_sort_del(sort);
	return (0);
}
