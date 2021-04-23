/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:12:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/23 17:35:34 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	check if stack is sorted in ascending order
**	(smallest number on top of stack)
*/

int	stack_is_sorted(t_stack *stack)
{
	t_list	*cursor;
	int		number;
	int		next;

	cursor = stack->head;
	while (cursor != NULL)
	{
		number = *((int *)cursor->content);
		if (cursor->next != NULL)
		{
			next = *((int *)cursor->next->content);
			if (number > next)
				return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

/*
**	check if the top N element of the stack is sorted in ascending order
**	(smallest number on top of stack)
*/

int	top_n_stack_is_sorted(t_stack *stack, int n)
{
	t_list	*cursor;
	int		number;
	int		next;

	cursor = stack->head;
	while (cursor != NULL && --n > 0)
	{
		number = *((int *)cursor->content);
		if (cursor->next != NULL)
		{
			next = *((int *)cursor->next->content);
			if (number > next)
				return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

/*
**	check if the top N element of the stack is sorted in DESCending order
**	(BIGGEST number on top of stack)
*/

int	top_n_stack_is_sorted_desc(t_stack *stack, int n)
{
	t_list	*cursor;
	int		number;
	int		next;

	cursor = stack->head;
	while (cursor != NULL && --n > 0)
	{
		number = *((int *)cursor->content);
		if (cursor->next != NULL)
		{
			next = *((int *)cursor->next->content);
			if (number < next)
				return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}
