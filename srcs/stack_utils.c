/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:35:17 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/20 16:43:58 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		ft_nums_el_of_mas(t_mas *tmp)
{
	t_mas	*mas;
	int		n;

	n = 0;
	mas = tmp;
	while (mas)
	{
		n++;
		mas = mas->next;
	}
	return (n);
}

t_mas	*ft_last_el_of_l(t_mas *temp)
{
	while (temp->next)
		temp = temp->next;
	return (temp);
}
