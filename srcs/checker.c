/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:25:18 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 16:51:02 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		main(int ac, char **av)
{
	t_sort	*sort;

	if ((sort = create_stack_sort(ac, av)) == NULL)
		error(sort);
	read_commands(sort);
	sort_del(sort);
	return (0);
}
