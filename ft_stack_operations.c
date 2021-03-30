/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:27:34 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/30 15:27:20 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**  swap the first 2 elements at the top of stack.
**  Do nothing if there is only one or no elements.
*/

void	swap_stack(t_stack *stack)
{
	t_list *old_top;
	t_list *new_top;

	if (stack->head && stack->size > 1)
	{
		old_top = ft_stack_pop(stack);
		new_top = ft_stack_pop(stack);
		ft_stack_push(stack, old_top);
		ft_stack_push(stack, new_top);
	}
}

/*
**  take the first element at the top of stack 1 and put it at
**	the top of stack 2.
**  Do nothing if stack 1 is empty.
*/

void	push_stack(t_stack *stack_src, t_stack *stack_dst)
{
	t_list *node;

	node = ft_stack_pop(stack_src);
	if (node != NULL)
		ft_stack_push(stack_dst, node);
}

/*
**  rotate: shift up all elements of stack a by 1. The first element becomes
**  the last one.
*/

void	rotate_stack(t_stack *stack)
{
	t_list *node;

	if (stack->head && stack->size > 1)
	{
		node = ft_stack_pop(stack);
		stack->tail->next = node;
		stack->size++;
		stack->tail = node;
		node->next = NULL;
	}
}

/*
**  reverse rotate: shift down all elements of stack a by 1.
**  The last element becomes the first one.
*/

void	reverse_rotate_stack(t_stack *stack)
{
	t_list *node;

	if (stack->head && stack->size > 1)
	{
		node = stack->head;
		while (node->next != NULL)
		{
			if (node->next->next == NULL)
				break ;
			node = node->next;
		}
		stack->tail->next = stack->head;
		stack->head = stack->tail;
		node->next = NULL;
		stack->tail = node;
	}
}
