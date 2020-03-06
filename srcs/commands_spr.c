/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_spr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:24:19 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 17:00:51 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	commands_s(t_mas *a, t_mas *b, int flag)
{
	int el;

	el = 0;
	if (a && a->next && (flag == 1 || flag == 3))
	{
		el = a->next->elem;
		a->next->elem = a->elem;
		a->elem = el;
	}
	if (b && b->next && (flag == 2 || flag == 3))
	{
		el = b->next->elem;
		b->next->elem = b->elem;
		b->elem = el;
	}
}

void	commands_p(t_mas **first, t_mas **second)
{
	t_mas *tmp;
	t_mas *del;

	if (*second)
	{
		tmp = one_elem_of_l((*second)->elem);
		if (*first != NULL)
			tmp->next = *first;
		*first = tmp;
		del = *second;
		*second = (*second)->next;
		del->next = NULL;
		mas_del(del);
	}
}

void	commands_r(t_mas **mas)
{
	t_mas	*tmp;
	t_mas	*del;

	if (*mas && (*mas)->next)
	{
		tmp = *mas;
		(*mas) = (*mas)->next;
		del = *mas;
		tmp->next = NULL;
		while ((*mas)->next)
			(*mas) = (*mas)->next;
		(*mas)->next = tmp;
		*mas = del;
	}
}

void	commands_rr(t_mas **mas)
{
	t_mas *tmp;
	t_mas *del;

	if (*mas && (*mas)->next)
	{
		tmp = *mas;
		while ((*mas)->next && (*mas)->next->next)
			*mas = (*mas)->next;
		del = (*mas)->next;
		del->next = tmp;
		(*mas)->next = NULL;
		*mas = del;
	}
}

void	commands_rr_rrr(t_mas **a, t_mas **b, int flag)
{
	if (flag == 1)
	{
		commands_r(a);
		commands_r(b);
	}
	else if (flag == 2)
	{
		commands_rr(a);
		commands_rr(b);
	}
}
