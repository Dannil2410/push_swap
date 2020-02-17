/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:25:18 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/17 14:07:59 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_sort	*sort;

	if ((sort = ft_create_stack_sort(ac, av)) == NULL)
		return (1);
	ft_conclusionab(sort->a, sort->b);
	ft_read_commands(sort);
	//освободить память для sort
	return (0);
}
