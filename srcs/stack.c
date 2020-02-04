/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:32:39 by tstripeb          #+#    #+#             */
/*   Updated: 2020/02/04 17:24:15 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_mas	*ft_one_elem_of_l(int number)
{
	t_mas *new;

	if ((new = (t_mas *)malloc(sizeof(t_mas))) == NULL)
		return (NULL);
	new->elem = number;
	new->next = NULL;
	return (new);
}

t_mas	*ft_create_masi(t_mas **tmp, int number)
{
	t_mas *new;
	t_mas *old;

	if ((new = ft_one_elem_of_l(number)) == NULL)
		return (NULL);
	if (*tmp == NULL)
	{
		*tmp = new;
		return (*tmp);
	}
	old = ft_last_el_of_l(*tmp);
	old->next = new;
	return (old);
}

void	ft_create_list_masa(t_sort *sort, int ac, char **av)
{
	int	i;
	int	value;
	
	av = (ac == 2 ? ft_strsplit(av[1], ' ') : av);
	i = (ac == 2 ? i = 0 : 1);
	while (ac == 2 ? (int)av[i] : i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
			sort->flag_v = 1;
		else
		{
			value = ft_atoi(av[i]);
			if ((ft_valid_val(value, av[i]) == 0) ||
					(ft_double_val(sort->a, value) == 0))
				ft_error_message(-1);//освобождение памяти и вывод error
			if ((ft_create_masi(&sort->a, value)) == NULL)
				ft_error_message(-1);//освобождение памяти и вывод error
		}
		i++;
	}
	sort->nums = ft_nums_el_of_mas(sort->a);
	//освободить память под av, если ac = 2
}

t_sort	*ft_create_stack_sort(int ac, char **av)
{
	t_sort *new;

	if ((new = (t_sort *)malloc(sizeof(t_sort))) == NULL)
		return (NULL);
	new->a = NULL;
	new->b = NULL;
	new->nums = 0;
	new->len_a = 0;
	new->len_b = 0;
	new->flag_v = 0;
	ft_create_list_masa(new, ac, av);
	return (new);
}
