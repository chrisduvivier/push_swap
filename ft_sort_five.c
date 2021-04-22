/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 01:14:45 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/22 12:41:03 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	insert_to_sorted_stack(t_checker *arg, int ra_size)
{
	t_list	*cursor;

	cursor = arg->stack_a->head;
	while (*(int *)arg->stack_b->head->content > (*(int *)cursor->content)
		&& (size_t)ra_size < arg->stack_a->size)
	{
		ft_stack_ra(arg);
		cursor = arg->stack_a->head;
		ra_size++;
	}
	ft_stack_pa(arg);
	return (ra_size);
}

/*
**	check position of head of b in the stack a. top midle or tail
**	push back to stack_a to appropriate place
*/

void	sort_five_number_helper(t_checker *arg, int top_of_b, int *ra_size)
{
	if (top_of_b < (*(int *)arg->stack_a->head->content))
	{
		ft_stack_pa(arg);
		if (arg->stack_b->size > 0)
			*ra_size = insert_to_sorted_stack(arg, *ra_size);
	}
	else if (top_of_b > (*(int *)arg->stack_a->tail->content))
	{
		while (arg->stack_b->size > 0)
		{	
			ft_stack_pa(arg);
			ft_stack_ra(arg);
		}
	}
	else
	{
		while (arg->stack_b->size > 0)
			*ra_size = insert_to_sorted_stack(arg, *ra_size);
	}
}

/*
**	ONLY WHEN STACK SIZE ITSELF IS 5
*/

void	sort_five_number(t_checker *arg)
{
	int	top_of_b;
	int	ra_size;

	while (arg->stack_a->size > 3)
		ft_stack_pb(arg);
	if (arg->stack_b->size == 2)
		sort_two_number(arg, 'b');
	sort_three_number(arg);
	ra_size = 0;
	top_of_b = *(int *)arg->stack_b->head->content;
	sort_five_number_helper(arg, top_of_b, &ra_size);
	if (ra_size > arg->max_size / 2)
	{
		while (ra_size++ < arg->max_size)
			ft_stack_ra(arg);
	}
	else
	{
		while (ra_size-- > 0)
			ft_stack_rra(arg);
	}
}

void	sort_less_than_five_number(t_checker *arg, int size)
{
	// ft_printf("   sort_less_than_five_number  size=[%d] \n", size);
	if (size == 2)
		sort_two_number(arg, 'a');
	else if (size == 3)
	{
		if (arg->max_size == 3)
			sort_three_number(arg);
		else
			sort_top_three_number(arg);
	}
	else if (arg->max_size == 5 || arg->max_size == 4)
	{
		sort_five_number(arg);
	}
	else
	{
		// ft_printf("=== sort_top_five_number ===\n");
		sort_top_five_number(arg, size);
	}
}
