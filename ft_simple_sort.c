/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:05:58 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/10 17:55:38 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_top_two_number(t_checker *arg, char stack_type)
{
	t_list	*cursor;

	if (stack_type == 'a')
	{
		cursor = arg->stack_a->head;
		if (*(int *)cursor->content > *(int *)cursor->next->content)
		{
			ft_stack_sa(arg);
		}
	}
	else
	{
		cursor = arg->stack_b->head;
		if (*(int *)cursor->content > *(int *)cursor->next->content)
		{
			ft_stack_sb(arg);
		}
	}
}

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
		push_stack(arg->stack_a, arg->stack_b);
	}
	while (arg->stack_b->size > 0)
	{
		tmp = *(int *)arg->stack_b->head->content;
		push_stack(arg->stack_b, arg->stack_a);
		rotate_stack(arg->stack_a);
		while (arg->stack_a->size > 0
			&& (*(int *)arg->stack_a->head->content <= tmp))
		{
			if (tmp == *(int *)arg->stack_a->head->content)
				break ;
			push_stack(arg->stack_a, arg->stack_b);
		}
		reverse_rotate_stack(arg->stack_a);
	}
}
