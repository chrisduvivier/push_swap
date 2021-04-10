/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:05:58 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/01 16:02:54 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    sort_top_two_number(t_checker *arg, char stack_type)
{
	t_list		*cursor;
	
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

void    sort_top_three_number(t_checker *arg)
{
    int			top;
	int			middle;
	int			bottom;
	t_list		*cursor;
	
	cursor = arg->stack_a->head;
	top = *(int *)cursor->content;
	middle = *(int *)cursor->next->content;
	bottom = *(int *)cursor->next->next->content;
	
	if (top > middle) 
	{
		if (middle > bottom)	
		{
			// 3 2 1
			ft_stack_sa(arg);
			ft_stack_ra(arg);
			ft_stack_ra(arg);
			ft_stack_pb(arg);
			ft_stack_rra(arg);
			ft_stack_rra(arg);
			ft_stack_pa(arg);
		}
		else if (top < bottom)
		{
			// 2 1 3
			ft_stack_sa(arg);
		}
		else // bottom > middle
		{
			// 3 1 2
			ft_stack_pb(arg);
			ft_stack_ra(arg);
			ft_stack_ra(arg);
			ft_stack_pa(arg);
			ft_stack_rra(arg);
			ft_stack_rra(arg);
		}
	}
	else if (middle > top)
	{
		if (top > bottom)
		{
			// 2 3 1
			ft_stack_ra(arg);
			ft_stack_ra(arg);
			ft_stack_pb(arg);
			ft_stack_rra(arg);
			ft_stack_rra(arg);
			ft_stack_pa(arg);
		}
		else if (middle < bottom)
		{
			// 1 2 3
			//	--
		}
		else // middle > bottom
		{
			// 1 3 2
			ft_stack_ra(arg);
			ft_stack_sa(arg);
			ft_stack_rra(arg);
		}
	}
}

void    sort_three_number(t_checker *arg)
{
    int			top;
	int			middle;
	int			bottom;
	t_list		*cursor;
	
	cursor = arg->stack_a->head;
	top = *(int *)cursor->content;
	middle = *(int *)cursor->next->content;
	bottom = *(int *)cursor->next->next->content;
	
	if (top > middle) 
	{
		if (middle > bottom)	
		{
			// 3 2 1
			ft_stack_sa(arg);
            ft_stack_rra(arg);
		}
		else if (top < bottom)
		{
			// 2 1 3
			// sa
            ft_stack_sa(arg);
		}
		else // bottom > middle
		{
			// 3 1 2
			// ra
            ft_stack_ra(arg);
		}
	}
	else if (middle > top)
	{
		if (top > bottom)
		{
			// 2 3 1
			// rra
            ft_stack_rra(arg);
		}
		else if (middle < bottom)
		{
			// 1 2 3
			//	
		}
		else // middle > bottom
		{
			// 1 3 2
            ft_stack_rra(arg);
            ft_stack_sa(arg);
		}
	}
}


// void    sort_less_than_seven_number(t_checker *arg)
// {
	
// }

/*
**	Repeat until the input_stack is not empty
**	Pop an element from input_stack call it tmp.
**	While aux_stack (B) is not empty and top of the aux_stack < tmp,
**	pop data from aux_stack and push it to the input_stack (A)
*/

void	simple_sort(t_checker *arg)
{
	int tmp;

	while (arg->stack_a->size > 0)
	{
		push_stack(arg->stack_a, arg->stack_b);
	}
	while (arg->stack_b->size > 0)
	{
		tmp = *(int *)arg->stack_b->head->content;
		push_stack(arg->stack_b, arg->stack_a);
		rotate_stack(arg->stack_a);
		while (arg->stack_a->size > 0 &&
			(*(int *)arg->stack_a->head->content <= tmp))
		{
			if (tmp == *(int *)arg->stack_a->head->content)
				break ;
			push_stack(arg->stack_a, arg->stack_b);
		}
		reverse_rotate_stack(arg->stack_a);
	}
}
