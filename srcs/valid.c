/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:11:20 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 17:08:06 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		valid_val(int value, char *str)
{
	char	*tmp;
	int		result;

	result = 0;
	tmp = ft_itoa(value);
	if (ft_strcmp(tmp, str) == 0)
		result = 1;
	if (tmp)
		free(tmp);
	return (result);
}

int		double_val(t_mas *a, int value)
{
	t_mas *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->elem == value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
