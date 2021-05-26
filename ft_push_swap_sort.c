/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:50:04 by cduvivie          #+#    #+#             */
/*   Updated: 2021/05/26 09:35:43 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	Check which chunk the head of stack b belongs to, and find how many
**	elements belongs to the same chunk
*/

int	count_number_of_element_in_chunk(t_checker *arg, t_stack *stack)
{
	int	chunk_index;

	if (stack->size != 0 && stack->head != NULL)
	{
		chunk_index = find_group_of_chunk(arg, *(int *)stack->head->content);
		if (chunk_index > arg->chunk_size)
		{
			ft_printf("ERROR: count_number_of_element_in_chunk\n");
			ft_printf("chunk_index=%d, arg->chunk_size=%d\n", chunk_index,
				arg->chunk_size);
		}
		return (arg->chunk_array[chunk_index].num_elements);
	}
	return (0);
}

void	push_swap_sort_small_list(t_checker *arg, int n)
{
	if (top_n_stack_is_sorted(arg->stack_a, n) == 1)
		sort_less_than_five_number(arg, n);
}

/*
**	1. split and create 2 chunks from stack_a.
**	2. Do (1) until stack_a->size is less than threshold SORT_SIZE.
*/

int	push_swap_sort_add_chunk(t_checker *arg, int size_of_top_a)
{
	while (size_of_top_a > SORT_SIZE)
	{
		size_of_top_a = create_chunk(arg, arg->stack_a, size_of_top_a);
	}
	return (size_of_top_a);
}

/*
**	We know N > 5: sort the big list
**
**	1. split and create 2 chunks from stack_a.
**	2. Do (1) until stack_a->size is less than threshold SORT_SIZE.
**	3. Start sorting the chunk on the stack A
*/

void	push_swap_sort_big_list(t_checker *arg)
{
	int	i;
	int	size_chunk;

	push_swap_sort_add_chunk(arg, arg->stack_a->size);
	push_swap_sort_small_list(arg, arg->stack_a->size);
	while (arg->stack_b->head != NULL && arg->stack_b->size != 0)
	{
		size_chunk = count_number_of_element_in_chunk(arg, arg->stack_b);
		while (size_chunk != 0)
		{
			i = 0;
			while (i++ < size_chunk)
				ft_stack_pa(arg);
			if (size_chunk <= SORT_SIZE)
				push_swap_sort_small_list(arg, size_chunk);
			else if (size_chunk > SORT_SIZE)
			{
				size_chunk = push_swap_sort_add_chunk(arg, size_chunk);
				push_swap_sort_small_list(arg, size_chunk);
			}
			size_chunk = count_number_of_element_in_chunk(arg, arg->stack_b);
		}
	}
}

void	push_swap_sort(t_checker *arg, int size)
{	
	arg->chunk_array = ft_calloc((int)(arg->max_size + 1), sizeof(t_chunk));
	if (!arg->chunk_array)
		free_and_exit(arg);
	arg->chunk_size = 0;
	if (arg->stack_a->size <= 5)
		sort_less_than_five_number(arg, size);
	else
	{
		push_swap_sort_big_list(arg);
	}
}
