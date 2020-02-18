/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:28:05 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/18 15:55:52 by tstripeb         ###   ########.fr       */
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

void	ft_mas_del(t_mas *mas)
{
	t_mas	*tmp;

	while (mas)
	{
		tmp = mas;
		mas = mas->next;
		ft_memdel((void **)(&tmp));
	}
}

void	ft_sort_del(t_sort *sort)
{
	ft_mas_del(sort->a);
	ft_mas_del(sort->b);
	ft_memdel((void **)(&sort));
}

void	ft_error(t_sort *sort)
{
	ft_sort_del(sort);
	write(1, "Error\n", 6);
	exit(0);
}
