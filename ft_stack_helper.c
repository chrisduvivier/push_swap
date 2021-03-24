/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:12:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/20 14:10:54 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"

void print_list_int(void *content)
{
	ft_printf("[%d]\n", *(int *)content);
}

/*
**  ft_printf("size: [%d] | head: [%d] | tail: %d\n",
**			stack->size,
**			*(int *)stack->head->content,
**			*(int *)stack->tail->content);
*/

void ft_stack_print(t_stack *stack)
{
	if (stack->head != NULL)
	{
		t_list *node = stack->head;
		ft_lstiter(node, *print_list_int);
	}
}

int	stack_is_sorted(t_stack *stack)
{
	t_list *cursor;
	int number;
	int next;

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
