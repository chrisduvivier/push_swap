/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:16:26 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/20 13:36:48 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**  bunch of non generic sorting function to satisfy the required
**  number of instructions defined by the subject.
*/

/*
**	ONLY FOR STACK A
**	handles 3 pattern from top:
**		3 2 1
**		2 1 3
**		3 1 2
*/

void	sort_top_three_number_helper_1(t_checker *arg, int top,
									int mid, int bottom)
{
	if (mid > bottom)
	{
		ft_stack_sa(arg);
		ft_stack_ra(arg);
		ft_stack_ra(arg);
		ft_stack_pb(arg);
		ft_stack_rra(arg);
		ft_stack_rra(arg);
		ft_stack_pa(arg);
	}
	else if (top < bottom)
		ft_stack_sa(arg);
	else
	{
		ft_stack_pb(arg);
		ft_stack_ra(arg);
		ft_stack_ra(arg);
		ft_stack_pa(arg);
		ft_stack_rra(arg);
		ft_stack_rra(arg);
	}
}

/*
**	ONLY FOR STACK A
**	handles 3 pattern from top:
**		2 3 1
**		1 3 2
**		1 2 3 (do nothing)
*/

void	sort_top_three_number_helper_2(t_checker *arg, int top,
									int mid, int bottom)
{
	if (top > bottom)
	{
		ft_stack_ra(arg);
		ft_stack_ra(arg);
		ft_stack_pb(arg);
		ft_stack_rra(arg);
		ft_stack_rra(arg);
		ft_stack_pa(arg);
	}
	else if (mid > bottom)
	{
		ft_stack_ra(arg);
		ft_stack_sa(arg);
		ft_stack_rra(arg);
	}
}

/*
**	Sort top 3 number of stack A
*/

void	sort_top_three_number(t_checker *arg)
{
	int		top;
	int		middle;
	int		bottom;
	t_list	*cursor;

	cursor = arg->stack_a->head;
	top = *(int *)cursor->content;
	middle = *(int *)cursor->next->content;
	bottom = *(int *)cursor->next->next->content;
	if (top > middle)
		sort_top_three_number_helper_1(arg, top, middle, bottom);
	else if (middle > top)
		sort_top_three_number_helper_2(arg, top, middle, bottom);
}

/*
**	handles 6 pattern from top:
**		3 2 1
**		2 1 3
**		3 1 2
**		2 3 1
**		1 3 2
**		1 2 3 (do nothing)
*/

void	sort_three_number_helper(t_checker *arg, int top, int mid, int bottom)
{
	if (top > mid)
	{
		if (mid > bottom)
		{
			ft_stack_sa(arg);
			ft_stack_rra(arg);
		}
		else if (top < bottom)
			ft_stack_sa(arg);
		else
			ft_stack_ra(arg);
	}
	else if (mid > top)
	{
		if (top > bottom)
			ft_stack_rra(arg);
		else if (mid > bottom)
		{
			ft_stack_rra(arg);
			ft_stack_sa(arg);
		}
	}
}

/*
**	only when stack's size is 3
*/

void	sort_three_number(t_checker *arg)
{
	int			top;
	int			middle;
	int			bottom;
	t_list		*cursor;

	cursor = arg->stack_a->head;
	top = *(int *)cursor->content;
	middle = *(int *)cursor->next->content;
	bottom = *(int *)cursor->next->next->content;
	sort_three_number_helper(arg, top, middle, bottom);
}
