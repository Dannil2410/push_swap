/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:36:13 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/17 14:04:36 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

int		ft_sorting_good(t_mas *a)
{
	t_mas	*tmp;
	int		nbr;
	int		flag;

	tmp = a;
	flag = 0;
	while (tmp->next)
	{
		nbr = tmp->elem;
		tmp = tmp->next;
		if (nbr > tmp->elem)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
		return (0);
	return (1);
}

void	ft_conclusionab(t_mas *a, t_mas *b)
{
	char	*el;

	while (a || b)
	{
		if (a)
		{
			el = ft_itoa(a->elem);
			ft_putstr(el);
			free(el);
			a = a->next;
		}
		else
			ft_putchar('-');
		ft_putstr(" | ");
		if (b)
		{
			el = ft_itoa(b->elem);
			ft_putstr(el);
			free(el);
			b = b->next;
		}
		else
			ft_putchar('-');
		ft_putchar('\n');
	}
}

void		ft_check_and_work(char *command, t_sort *sort)
{
	if (ft_strcmp(command, "sa") == 0)
		ft_commands_s(sort->a, sort->b, 1);
	else if (ft_strcmp(command, "sb") == 0)
		ft_commands_s(sort->a, sort->b, 2);
	else if (ft_strcmp(command, "ss") == 0)
		ft_commands_s(sort->a, sort->b, 3);
	else if (ft_strcmp(command, "pa") == 0)
		ft_commands_p(&sort->a, &sort->b);
	else if (ft_strcmp(command, "pb") == 0)
		ft_commands_p(&sort->b, &sort->a);
	else if (ft_strcmp(command, "ra") == 0)
		ft_commands_r(&sort->a);
	else if (ft_strcmp(command, "rb") == 0)
		ft_commands_r(&sort->b);
	else if (ft_strcmp(command, "rr") == 0)
		ft_commands_rr_rrr(&sort->a, &sort->b, 1);
	else if (ft_strcmp(command, "rra") == 0)
		ft_commands_rr(&sort->a);
	else if (ft_strcmp(command, "rrb") == 0)
		ft_commands_rr(&sort->b);
	else if (ft_strcmp(command, "rrr") == 0)
		ft_commands_rr_rrr(&sort->a, &sort->b, 2);
	else
		ft_error_message(-1);//освободить полностью память для sort
}

void	ft_read_commands(t_sort *sort)
{
	char	*command;

	while (get_next_line(0, &command) > 0)
	{
		ft_check_and_work(command, sort);
		if (command)
			ft_strdel(&command);
		if (sort->flag_v)
			ft_conclusionab(sort->a, sort->b);
		ft_putstr("\na | b\n-----\n");
	}
	if (sort->b == NULL && ft_sorting_good(sort->a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
