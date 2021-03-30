/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:43:25 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/30 15:38:56 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	Function to sort an array using insertion sort
*/

void	insertion_sort(int *arr, int size)
{
	int i;
	int key;
	int j;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

int		find_median(t_stack *stack, int size)
{
	int		array[size];
	t_list	*cursor;
	int		count;

	count = 0;
	cursor = stack->head;
	while (cursor && count < size)
	{
		array[count++] = *(int *)cursor->content;
		cursor = cursor->next;
	}
	insertion_sort(array, size);
	return (array[size / 2]);
}

/*
**	rotate list 1 forward top_half_len times (larger half to front)
**	recursively call this on bigger half
**	reverse list back to original position
**	rotate list 1 backward top_half_len times
*/

void	quick_sort_helper_large(t_checker *arg, int n, int *top_half_len)
{
	int i;

	i = 0;
	while (i++ < *(top_half_len))
		ft_stack_ra(arg);
	quick_sort(arg, n - *(top_half_len));
	i = 0;
	while (i++ < *(top_half_len))
		ft_stack_rra(arg);
}

/*
**	filter all values below the median into list 2:
**	- list 2 stores the larger half
**	- reverse the list back to original position
**	- push back smaller half onto larger half
*/

void	quick_sort_helper_small(t_checker *arg, int n, int *top_half_len)
{
	int i;
	int median;

	i = 0;
	median = find_median(arg->stack_a, n);
	while (i++ < n)
	{
		if (*(int *)arg->stack_a->head->content < median)
		{
			ft_stack_pb(arg);
			(*top_half_len)++;
		}
		else
			ft_stack_ra(arg);
	}
	i = 0;
	while (i++ < n - *(top_half_len))
		ft_stack_rra(arg);
	i = 0;
	while (i++ < *(top_half_len))
		ft_stack_pa(arg);
}

/*
**	https://stackoverflow.com/questions/33704858/
**	sorting-2-linked-list-of-50000-numbers-with-a-limited-set-of-operations
*/

void	quick_sort(t_checker *arg, int n)
{
	int top_half_len;

	if (n == 0 || n == 1)
		return ;
	top_half_len = 0;
	quick_sort_helper_small(arg, n, &top_half_len);
	quick_sort(arg, top_half_len);
	quick_sort_helper_large(arg, n, &top_half_len);
}
