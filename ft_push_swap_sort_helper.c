/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort_helper.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:43:08 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/23 17:54:23 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	fill chunk based on the last call to split_stack_a_with_median.
**	fill date and increment chunk_size
*/

void	fill_chunk_data(t_checker *arg, t_list *head, int size_chunk)
{
	int		count;
	int		number;
	t_chunk	*chunk;

	count = 0;
	chunk = &(arg->chunk_array[arg->chunk_size]);
	chunk->max_num = INT_MIN;
	chunk->min_num = INT_MAX;
	chunk->num_elements = size_chunk;
	while (head != NULL && count < size_chunk)
	{
		number = *(int *)head->content;
		if (number > chunk->max_num)
			chunk->max_num = number;
		if (number < chunk->min_num)
			chunk->min_num = number;
		head = head->next;
		count++;
	}
	arg->chunk_size++;
}

/*
**	checks wchih direction is faster
*/

void	split_stack_a_with_median_helper(t_checker *arg, int rra_needed)
{
	int	i;

	i = 0;
	if ((arg->stack_a->size) > (size_t)(2 * rra_needed))
	{
		while (i++ < (rra_needed))
			ft_stack_rra(arg);
	}
	else
	{
		while (i++ < (int)(arg->stack_a->size - (size_t)rra_needed))
			ft_stack_ra(arg);
	}
}

/*
**	push all element smaller than median to B.
*/

int	split_stack_a_with_median(t_checker *arg, int median, int size_stack)
{
	int	i;
	int	b_size;

	i = 0;
	b_size = 0;
	while (i++ < size_stack)
	{
		if (*(int *)arg->stack_a->head->content < median)
		{
			ft_stack_pb(arg);
			b_size++;
		}
		else
			ft_stack_ra(arg);
	}
	fill_chunk_data(arg, arg->stack_a->head, size_stack - b_size);
	fill_chunk_data(arg, arg->stack_b->head, b_size);
	split_stack_a_with_median_helper(arg, size_stack - b_size);
	return (size_stack - b_size);
}

/*
**	split stack A into 2
*/

int	create_chunk(t_checker *arg, t_stack *stack_a, int size_to_split)
{
	int	median;
	int	splitted_size_a;

	median = find_median(arg, stack_a, size_to_split);
	splitted_size_a = split_stack_a_with_median(arg, median, size_to_split);
	return (splitted_size_a);
}

/*
**	Function to find out which chink a value belongs to, with the help of
**	the sorted array of median values.
**	if array of median: 5 10 20 40
**	all value <= 5 -> chunk 0
**	all value <= 10 -> chunk 1 etc...
**	all value > 40 -> chunk (num_median+1)
*/

int	find_group_of_chunk(t_checker *arg, int number)
{
	int	i;
	int	res;
	int	size_of_chunk;

	i = 0;
	res = -1;
	size_of_chunk = INT_MAX;
	while (i < arg->chunk_size)
	{
		if (number >= arg->chunk_array[i].min_num
			&& number <= arg->chunk_array[i].max_num)
		{
			if (arg->chunk_array[i].num_elements < size_of_chunk)
				size_of_chunk = arg->chunk_array[i].num_elements;
			res = i;
		}
		i++;
	}
	if (res == -1)
		ft_printf("ERROR: find_group_of_chunk\n");
	return (res);
}
