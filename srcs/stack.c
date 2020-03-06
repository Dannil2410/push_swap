/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:32:39 by tstripeb          #+#    #+#             */
/*   Updated: 2020/03/06 17:07:20 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_mas	*one_elem_of_l(int number)
{
	t_mas *new;

	if ((new = (t_mas *)malloc(sizeof(t_mas))) == NULL)
		return (NULL);
	new->elem = number;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_mas	*create_masi(t_mas **tmp, int number)
{
	t_mas *new;
	t_mas *old;

	if ((new = one_elem_of_l(number)) == NULL)
		return (NULL);
	if (*tmp == NULL)
	{
		*tmp = new;
		return (*tmp);
	}
	old = last_el_of_l(*tmp);
	old->next = new;
	return (old);
}

void	create_list_masa(t_sort *sort, int ac, char **av)
{
	int	i;
	int	value;

	av = (ac == 2 ? ft_strsplit(av[1], ' ') : av);
	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (ac == 2 ? (int)av[i] : i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
			sort->flag_v = 1;
		else
		{
			value = ft_atoi(av[i]);
			if ((valid_val(value, av[i]) == 0) ||
					(double_val(sort->a, value) == 0))
				error(sort);
			if ((create_masi(&sort->a, value)) == NULL)
				error(sort);
		}
		i++;
	}
	sort->nums = nums_el_of_mas(sort->a);
	av = (ac == 2 ? freetime(av, sort->nums, sort->flag_v) : NULL);
}

t_sort	*create_stack_sort(int ac, char **av)
{
	t_sort *new;

	if ((new = (t_sort *)malloc(sizeof(t_sort))) == NULL)
		return (NULL);
	new->a = NULL;
	new->b = NULL;
	new->max_sort = NULL;
	new->nums = 0;
	new->len_b = 0;
	new->flag_v = 0;
	new->tmp_a = 0;
	new->tmp_b = 0;
	new->t_place = 0;
	new->need_a = 0;
	new->need_b = 0;
	new->n_place = 0;
	create_list_masa(new, ac, av);
	new->len_a = new->nums;
	return (new);
}
