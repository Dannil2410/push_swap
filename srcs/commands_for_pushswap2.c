/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_pushswap2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 11:54:04 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 18:18:27 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	search_max_sort(t_sort *sort)
{
	t_mas	*mas;
	int		nbrofcom;
	int		tmp;
	int		n;

	ft_index(sort->a);
	mas = sort->b;
	sort->max_sort = max_sort(sort->a, sort, mas);
	tmp = sort->len_a - sort->max_sort->i - sort->max_sort->sort;
	n = sort->max_sort->sort - (sort->len_a - sort->max_sort->i);
	if (tmp <= 0)
		nbrofcom = (n >= sort->len_a - n ? sort->len_a - tmp * (-1)
				: tmp * (-1));
	else
		nbrofcom = (tmp <= sort->len_a - tmp ? tmp : sort->len_a - tmp);
	while (nbrofcom)
	{
		if (tmp <= 0)
			check_and_work(n <= sort->len_a - n ?
				"ra" : "rra", sort, 1);
		else
			check_and_work(tmp < sort->len_a - tmp ?
				"rra" : "ra", sort, 1);
		nbrofcom--;
	}
}

t_mas	*max_sort(t_mas *a, t_sort *s, t_mas *mas)
{
	t_mas	*tmp;
	t_mas	*lst;

	tmp = a;
	lst = NULL;
	mas = NULL;
	while (tmp)
	{
		if (tmp->next && tmp->elem < tmp->next->elem)
		{
			lst = tmp;
			while (lst->next && lst->elem < lst->next->elem)
			{
				tmp->sort++;
				lst = lst->next;
			}
		}
		if (lst)
			mas = (lst->next == NULL && lst->elem < a->elem ? a : NULL);
		tmp->sort += (mas != NULL ? mas->sort : 0);
		s->max_sort = (s->max_sort == NULL || s->max_sort->sort <=
				tmp->sort ? tmp : s->max_sort);
		tmp = tmp->next;
	}
	return (s->max_sort);
}

int		mincmdspastone(t_sort *sort, t_mas *ma, int b_el, int b_i)
{
	t_mas	*paste;
	int		delta;
	int		delta_1;

	delta = 0;
	while (ma)
	{
		delta_1 = ma->elem - b_el;
		if ((delta == 0) || (delta < 0 && delta_1 < 0 &&
			delta_1 > delta) || (delta > 0 && delta_1 > 0
				&& delta_1 < delta))
		{
			delta = delta_1;
			paste = ma;
		}
		if (!ma->next)
			break ;
		ma = ma->next;
	}
	if (paste == ma && delta < 0)
		sort->t_place = -1;
	else
		sort->t_place = (delta < 0 ? paste->i + 1 : paste->i);
	return (mincmdspastwo(sort, b_el, b_i));
}

int		mincmdspastwo(t_sort *sort, int b_el, int b_i)
{
	sort->tmp_b = (sort->len_b / 2 >= b_i ? b_i :
			(sort->len_b - b_i) * (-1));
	sort->tmp_a = (sort->len_a / 2 >= sort->t_place ?
			sort->t_place : (sort->len_a - sort->t_place) * (-1));
	if (sort->t_place == -1)
		return (ft_modul(sort->tmp_b));
	else if (sort->t_place != -1 && sort->tmp_b > 0 && sort->tmp_a > 0)
		return (sort->tmp_a > sort->tmp_b ? sort->tmp_a : sort->tmp_b);
	else if (sort->t_place != -1 && sort->tmp_b < 0 && sort->tmp_a < 0)
		return (sort->tmp_a < sort->tmp_b ? ft_modul(sort->tmp_a) :
			ft_modul(sort->tmp_b));
	else
		return (ft_modul(sort->tmp_a) + ft_modul(sort->tmp_b));
}

void	return_a(t_sort *sort)
{
	t_mas	*mb;
	int		min_cmds;
	int		nbr_cmds;

	while (sort->b)
	{
		mb = sort->b;
		ft_index(sort->a);
		ft_index(sort->b);
		sort->len_a = nums_el_of_mas(sort->a);
		sort->len_b = nums_el_of_mas(mb);
		min_cmds = mincmdspastone(sort, sort->a, mb->elem, mb->i);
		neednbrofcmds(sort, 1);
		while (mb)
		{
			nbr_cmds = mincmdspastone(sort, sort->a, mb->elem, mb->i);
			if (nbr_cmds < min_cmds)
			{
				min_cmds = nbr_cmds;
				neednbrofcmds(sort, 1);
			}
			mb = mb->next;
		}
		paste_to_a(sort);
	}
}
