/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:36:13 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/04 17:24:13 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		ft_read_commands(t_sort *sort)
{
	char *command;

	while (get_next_line(0, &command) > 0)
	{
		ft_check_and_work(command, sort);
		if (command)
			ft_strdel(&command);
	}
}
