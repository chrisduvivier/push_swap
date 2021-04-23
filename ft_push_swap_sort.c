/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:50:04 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/23 16:48:44 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#define SORT_SIZE 5

void	print_chunks(t_checker *arg)
{
	int i = 0;
	while (i < arg->chunk_size)
	{
		ft_printf("chunk%d: min=%d --- max=%d | size=%d\n", i, arg->chunk_array[i].min_num, arg->chunk_array[i].max_num, arg->chunk_array[i].num_elements);
		i++;
	}
}

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
		number = *(int*)head->content;
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
**	push all element smaller than median to B.
*/

int	split_stack_a_with_median(t_checker *arg, int median, int size_stack)
{
	int		i;
	int		b_size;
	size_t	number_of_rra_needed;
	
	i = 0;
	b_size = 0;
	ft_printf("median=[%d]\n", median);
	// ft_printf("\nBEFORE split median");
	// print_stacks(arg);
	while (i++ < size_stack) //iterate through all
	{
		if (*(int *)arg->stack_a->head->content < median) //compare
		{
			ft_stack_pb(arg);	//push to b
			b_size++;
		}
		else
			ft_stack_ra(arg);	//less than median, so just rotate and look at next
	}
	number_of_rra_needed = (size_t)(size_stack - b_size);
	fill_chunk_data(arg, arg->stack_a->head, size_stack - b_size);	//left chunk
	fill_chunk_data(arg, arg->stack_b->head, b_size);					//right chunk
	

	// TODO: optimize by looking which way is faster
	i = 0;
	if ((arg->stack_a->size - (number_of_rra_needed)) > (number_of_rra_needed))
	{
		while (i++ < (int)(number_of_rra_needed))		//bring back to position
			ft_stack_rra(arg);
	}
	else
	{
		while (i++ < (int)(arg->stack_a->size - number_of_rra_needed))		//bring back to position
			ft_stack_ra(arg);
	}
	
	// ft_printf("\nAFTER split median");
	// print_stacks(arg);
	
	return (size_stack - b_size);
}

/*
**	push all element bigger than median in stack B to A.
**	return the size of the chunk added to the stack_a (a_size)
*/

int	split_stack_b_with_median(t_checker *arg, int median, int size_stack)
{
	int		i;
	int		a_size;
	size_t	number_of_rrb_needed;
	
	i = 0;
	a_size = 0;
	ft_printf("median=[%d]\n", median);
	while (i++ < size_stack) //iterate through all
	{
		if (*(int *)arg->stack_b->head->content >= median) //compare
		{
			ft_stack_pa(arg);	//push to a
			a_size++;
		}
		else
			ft_stack_rb(arg);	//less than median, so just rotate and look at next
	}
	number_of_rrb_needed = (size_t)(size_stack - a_size);
	fill_chunk_data(arg, arg->stack_b->head, size_stack - a_size);	//left chunk
	fill_chunk_data(arg, arg->stack_a->head, a_size);					//right chunk
	

	// TODO: optimize by looking which way is faster
	i = 0;
	if ((arg->stack_b->size - (number_of_rrb_needed)) > (number_of_rrb_needed))
	{
		while (i++ < (int)(number_of_rrb_needed))		//bring back to position
			ft_stack_rrb(arg);
	}
	else
	{
		while (i++ < (int)(arg->stack_b->size - number_of_rrb_needed))		//bring back to position
			ft_stack_rb(arg);
	}
	
	// ft_printf("\nAFTER split median");
	// print_stacks(arg);
	
	return (a_size);
}

int	create_chunk_stack_a(t_checker *arg, t_stack *stack_a, int size_to_split)
{
	int 	median;
	int		splitted_size_a;

	ft_printf("~~~~ create_chunk_stack_a ~~~~\n");
	//split stack A into 2
	print_stacks(arg);
	median = find_median(arg, stack_a, size_to_split);
	splitted_size_a = split_stack_a_with_median(arg, median, size_to_split);
	print_stacks(arg);
	ft_printf("~~~~ ~~~~~~~~~~~~ ~~~~\n");
	return (splitted_size_a);

}

int	create_chunk_stack_b(t_checker *arg, t_stack *stack_b, int size_to_split)
{
	int 	median;
	int		new_chunk_size_of_a;

	ft_printf("~~~~ create_chunk_stack_b ~~~~\n");
	//split stack A into 2
	print_stacks(arg);
	ft_printf("create_chunk_stack_b***** size_to_split=[%d]\n");
	median = find_median(arg, stack_b, size_to_split);
	new_chunk_size_of_a = split_stack_b_with_median(arg, median, size_to_split);
	print_stacks(arg);
	ft_printf("~~~~ ~~~~~~~~~~~~ ~~~~\n");
	return (new_chunk_size_of_a);

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
	int i;
	int res;
	int size_of_chunk;
	
	i = 0;
	res = -1;
	size_of_chunk = INT_MAX;
	while (i < arg->chunk_size)
	{
		if (number >= arg->chunk_array[i].min_num && number <= arg->chunk_array[i].max_num)
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

/*
**	Check which chunk the head of stack b belongs to, and find how many
**	elements belongs to the same chunk
*/

int	count_number_of_element_in_chunk(t_checker *arg, t_stack *stack)
{
	int	chunk_index;
	int count;

	// ft_printf("count_number_of_element_in_chunk: \n");

	count = 0;
	if (stack->size != 0 && stack->head != NULL)
	{
		chunk_index = find_group_of_chunk(arg, *(int *)stack->head->content);
		// ft_printf("[%d] is in chunk [%d] | size=[%d]\n", *(int *)stack->head->content, chunk_index, arg->chunk_array[chunk_index].num_elements);
		if (chunk_index > arg->chunk_size)
		{
			ft_printf("ERROR: count_number_of_element_in_chunk\n");
			ft_printf("chunk_index=%d, arg->chunk_size=%d\n", chunk_index, arg->chunk_size);
		}
		return (arg->chunk_array[chunk_index].num_elements);
	}
	return (0);
}


void	push_swap_sort_small_list(t_checker *arg, int n)
{
	if (top_n_stack_is_sorted(arg->stack_a, n) == 1)
		sort_less_than_five_number(arg, n);
	// ft_printf("SORTED TOP [%d] of stack_a\n", n);
	// print_stacks(arg);
}

/*
**	1. split and create 2 chunks from stack_a.
**	2. Do (1) until stack_a->size is less than threshold SORT_SIZE.
*/

int	push_swap_sort_big_list_add_chunk(t_checker *arg, int size_of_top_a)
{
	while (size_of_top_a > SORT_SIZE)
	{
		size_of_top_a = create_chunk_stack_a(arg, arg->stack_a, size_of_top_a);
	}
	// print_chunks(arg);			// check
	// print_stacks(arg);
	return (size_of_top_a);
}

/*
**	if the chunk of the top of stack_b is bigger SORT_SIZE:
**	split and create 2 chunks from the top of stack_b.
*/

int	push_swap_sort_add_chunk_from_stack_b(t_checker *arg, int size_of_top_b)
{
	int size_of_top_a;

	if (size_of_top_b > SORT_SIZE)
	{
		size_of_top_a = create_chunk_stack_b(arg, arg->stack_b, size_of_top_b);
	}
	if (size_of_top_b <= SORT_SIZE)
	{
		// size_of_top_b = 
	}
	return (size_of_top_b);
}

int	rotate_for_next_chunk(t_checker *arg)
{
	return (arg->max_size);
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
	int i;
	int size_chunk;

	push_swap_sort_big_list_add_chunk(arg, arg->stack_a->size);
	push_swap_sort_small_list(arg, arg->stack_a->size);
	
	while (arg->stack_b->head != NULL && arg->stack_b->size != 0)
	{
		size_chunk = count_number_of_element_in_chunk(arg, arg->stack_b);
		while (size_chunk != 0)
		{
			if (size_chunk > SORT_SIZE)
			{

				// ft_printf("&&&&&&&&&&&&&&\n");
				print_stacks(arg);
				size_chunk = create_chunk_stack_b(arg, arg->stack_b, size_chunk);
				// ft_printf("&            &\n");
				if (top_n_stack_is_sorted(arg->stack_a, size_chunk) == 1)
				{
					size_chunk = count_number_of_element_in_chunk(arg, arg->stack_a);
					if (size_chunk > SORT_SIZE)
						size_chunk = push_swap_sort_big_list_add_chunk(arg, size_chunk);
					push_swap_sort_small_list(arg, size_chunk);
				}
				// ft_printf("%%%%%%%%%%%%%%\n");
				print_stacks(arg);
			}
			else		//sortable size
			{
				// TODO: sort as you pa
				i = 0;
				while (i++ < size_chunk)
					ft_stack_pa(arg);
				if (top_n_stack_is_sorted(arg->stack_a, size_chunk) == 1)
				{
					if (size_chunk > SORT_SIZE)
						size_chunk = push_swap_sort_big_list_add_chunk(arg, size_chunk);
					push_swap_sort_small_list(arg, size_chunk);
				}
			}
			size_chunk = count_number_of_element_in_chunk(arg, arg->stack_b);
			ft_printf("next chunk:「%d\n", size_chunk);
			print_stacks(arg);
		}
	}
}

void	push_swap_sort(t_checker *arg, int size)
{	
	// setup chunks
	arg->chunk_array = malloc(sizeof(t_chunk) * (int)(arg->max_size + 1));
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
