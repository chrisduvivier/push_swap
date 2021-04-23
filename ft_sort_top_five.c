/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_top_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 01:14:45 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/23 17:59:10 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_top_five_number_helper(t_checker *arg, int size,
	int ra_size, int j)
{
	while (j-- > 0)
		ft_stack_rra(arg);
	if (ra_size == 3)
		sort_top_three_number(arg);
	else
		sort_two_number(arg, 'a');
	sort_two_number_b(arg);
	while (ra_size++ < size)
		ft_stack_pa(arg);
}

/*
**	Sort top 5 number of the stack A
*/

void	sort_top_five_number(t_checker *arg, int size)
{	
	int	i;
	int	median;
	int	ra_size;
	int	j;

	i = 0;
	j = 0;
	ra_size = size;
	median = find_median(arg, arg->stack_a, size);
	while (i++ < size)
	{
		if (*(int *)arg->stack_a->head->content < median)
		{
			ft_stack_pb(arg);
			ra_size--;
		}
		else
		{
			ft_stack_ra(arg);
			j++;
		}
	}
	sort_top_five_number_helper(arg, size, ra_size, j);
}
