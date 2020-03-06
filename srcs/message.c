/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:28:05 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 17:01:35 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

char	**freetime(char **av, int nums, int flag_v)
{
	int index;

	index = 0;
	nums = (flag_v == 1 ? nums++ : nums);
	while (index < nums)
	{
		free(av[index]);
		index++;
	}
	free(av);
	return (0);
}

void	mas_del(t_mas *mas)
{
	t_mas	*tmp;

	while (mas)
	{
		tmp = mas;
		mas = mas->next;
		ft_memdel((void **)(&tmp));
	}
}

void	sort_del(t_sort *sort)
{
	mas_del(sort->a);
	mas_del(sort->b);
	ft_memdel((void **)(&sort));
}

void	error(t_sort *sort)
{
	sort_del(sort);
	write(1, "Error\n", 6);
	exit(0);
}

void	putcommand(char *command)
{
	ft_putstr(command);
	ft_putchar('\n');
}
