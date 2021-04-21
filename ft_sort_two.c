/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:05:58 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/20 15:15:57 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	Sort top 2 number in the stack A
*/

void	sort_two_number(t_checker *arg, char stack_type)
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
**	Sort top 2 number in the stack B
**	(in reverse order: bigger to top, small bottom)
*/

void	sort_two_number_b(t_checker *arg)
{
	t_list	*cursor;

	if (arg->stack_b->size > 1)
	{
		cursor = arg->stack_b->head;
		if (*(int *)cursor->content < *(int *)cursor->next->content)
		{
			ft_stack_sb(arg);
		}
	}
}
