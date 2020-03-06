/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_pushswap3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:48:31 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 16:59:16 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	neednbrofcmds(t_sort *sort, int flag)
{
	if (flag == 1)
	{
		sort->need_a = sort->tmp_a;
		sort->need_b = sort->tmp_b;
		sort->n_place = sort->t_place;
	}
	else
	{
		sort->tmp_a = ft_modul(sort->need_a);
		sort->tmp_b = ft_modul(sort->need_b);
	}
}

void	paste_to_a(t_sort *sort)
{
	neednbrofcmds(sort, 2);
	if ((sort->need_b > 0 && sort->need_a > 0)
			|| (sort->need_b < 0 && sort->need_a < 0))
	{
		while (sort->tmp_a && sort->tmp_b && sort->n_place != -1)
		{
			check_and_work(sort->need_b > 0 && sort->need_a > 0 ?
					"rr" : "rrr", sort, 1);
			sort->tmp_a--;
			sort->tmp_b--;
		}
	}
	if (sort->tmp_b)
	{
		while (sort->tmp_b--)
			check_and_work(sort->need_b > 0 ? "rb" : "rrb", sort, 1);
	}
	if (sort->tmp_a)
	{
		while (sort->tmp_a-- && sort->n_place != -1)
			check_and_work(sort->need_a > 0 ? "ra" : "rra", sort, 1);
	}
	check_and_work("pa", sort, 1);
	if (sort->n_place == -1)
		check_and_work("ra", sort, 1);
}
