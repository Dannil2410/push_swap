/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:25:18 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/20 14:11:10 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		main(int ac, char **av)
{
	t_sort	*sort;

	if ((sort = ft_create_stack_sort(ac, av)) == NULL)
		ft_error(sort);
	ft_read_commands(sort);
	ft_sort_del(sort);
	return (0);
}
