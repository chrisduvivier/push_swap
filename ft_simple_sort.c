/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:05:58 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/23 17:41:59 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	Repeat until the input_stack is not empty
**	Pop an element from input_stack call it tmp.
**	While aux_stack (B) is not empty and top of the aux_stack < tmp,
**	pop data from aux_stack and push it to the input_stack (A)
*/

void	simple_sort(t_checker *arg)
{
	int	tmp;

	while (arg->stack_a->size > 0)
	{
		ft_stack_pb(arg);
	}
	while (arg->stack_b->size > 0)
	{
		tmp = *(int *)arg->stack_b->head->content;
		ft_stack_pa(arg);
		if (arg->stack_a->size > 1)
			ft_stack_ra(arg);
		while (arg->stack_a->size > 0
			&& (*(int *)arg->stack_a->head->content <= tmp))
		{
			if (tmp == *(int *)arg->stack_a->head->content)
				break ;
			ft_stack_pb(arg);
		}
		if (arg->stack_a->size > 1)
			ft_stack_rra(arg);
	}
}

/*
**	Simple sort with defined number of elements
*/

void	simple_sort_n(t_checker *arg)
{
	int	tmp;

	while (arg->stack_a->size > 0)
	{
		ft_stack_pb(arg);
	}
	while (arg->stack_b->size > 0)
	{
		tmp = *(int *)arg->stack_b->head->content;
		ft_stack_pa(arg);
		ft_stack_ra(arg);
		while (arg->stack_a->size > 0
			&& (*(int *)arg->stack_a->head->content <= tmp))
		{
			if (tmp == *(int *)arg->stack_a->head->content)
				break ;
			ft_stack_pb(arg);
		}
		ft_stack_rra(arg);
	}
}
