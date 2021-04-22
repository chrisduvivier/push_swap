/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_top_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 01:14:45 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/22 12:41:21 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	Sort top 5 number of the stack A
*/

void	sort_top_five_number(t_checker *arg, int size)
{	
	int	i;
	int	median;
	int ra_size;

	i = 0;
	int j = 0;
	ra_size = size;
	median = find_median(arg, arg->stack_a, size);
	// ft_printf("find_median of size=%d -> median= %d)\n", size, median);

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
	while (j-- > 0)
		ft_stack_rra(arg);
	// ft_printf("// sort left part -> if (ra_size == %d)\n", ra_size);
	if (ra_size == 3)
	{
		// ft_printf("NEXT: sort_top_three_number\n");
		sort_top_three_number(arg);	//sort top stack A
	}
	else
		sort_two_number(arg, 'a');
	sort_two_number_b(arg);
	while (ra_size++ < size)
		ft_stack_pa(arg);
}
