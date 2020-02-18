/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_for_pushswap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:53 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/18 17:38:57 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		ft_comparefirsttwoelem(t_mas *mas)
{
	if (mas->elem > mas->elem->next)
		return (1);
	else
		return (0);
}

int		ft_increasetolast(t_mas *mas)
{
	t_mas	*tmp;

	tmp = mas;
	while (tmp->next->next)
	{
		if (tmp->elem > tmp->next->elem)
			return (0);
		tmp = tmp->next;
		if (tmp->next->next == NULL)
		{
			if (tmp->elem > tmp->next->elem)
				return (1);
			else
				return (2);
		}
	}
	return (0);
}

int		ft_increasewithsecond(t_mas *mas)
{
	t_mas	*tmp;
	int		result;

	tmp = mas->next;
	result = 1;
	while (tmp->next)
	{
		if (tmp->elem > tmp->next->elem)
		{
			result = 0;
			break ;
		}
		tmp = tmp->next;
	}
	if (mas->elem > mas->next->elem && result == 1)
		return (result);
	else if (mas->elem < mas->next->elem && result == 1)
		return (result + 1);
	return (result);
}
