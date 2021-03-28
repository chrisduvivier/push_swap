/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:27:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/28 15:46:16 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"

/*
**	Function to sort an array using insertion sort
*/

void insertion_sort(int *arr, int size)
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
	int	array[size];
	t_list *cursor;
	int count;
	
	count = 0;
	cursor = stack->head;
	while (cursor && count < size)
	{
		array[count++] = *(int *)cursor->content;
		cursor = cursor->next;
	}
	ft_printf("FIND_MEDIAN call INSERTIONSORT\n");
	insertion_sort(array, size);
	ft_printf("MDEIAN: [%d]\n", array[size/2]);
	return array[size/2];
}

void	quick_sort_helper_large(t_checker *arg, int n, int *top_half_len)
{
	int i;

	i = 0;
	//rotate list 1 forward top_half_len times (larger half to front)
	while (i++ < *(top_half_len))
		rotate_stack(arg->stack_a);

	//recursively call this on bigger half
	quick_sort(arg, n - *(top_half_len));

	//reverse list back to original position
    // rotate list 1 backward top_half_len times
	i = 0;
	while (i++ < *(top_half_len))
		reverse_rotate_stack(arg->stack_a);
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
			push_stack(arg->stack_a, arg->stack_b);
			(*top_half_len)++;
		}
		else
			rotate_stack(arg->stack_a);
	}
	i = 0;
	while (i++ < n - *(top_half_len))
		reverse_rotate_stack(arg->stack_a);
	i = 0;
	while (i++ < *(top_half_len))
		push_stack(arg->stack_b, arg->stack_a);
}


/*
**	https://stackoverflow.com/questions/33704858/sorting-2-linked-list-of-50000-numbers-with-a-limited-set-of-operations
*/

void	quick_sort(t_checker *arg, int n)
{	
	int top_half_len;

	if (n == 0 || n == 1)
		return;
	top_half_len = 0;
	quick_sort_helper_small(arg, n, &top_half_len);
	quick_sort(arg, top_half_len);
	quick_sort_helper_large(arg, n, &top_half_len);
}


void	simple_sort(t_checker *arg)
{
	int tmp;
	
	while (arg->stack_a->size > 0)
	{
		push_stack(arg->stack_a, arg->stack_b);
	}
	print_stacks(arg);
	while (arg->stack_b->size > 0) // Repeat until the input_stack is not empty
	{
		tmp = *(int *)arg->stack_b->head->content; // Pop an element from input_stack call it tmp.
		push_stack(arg->stack_b, arg->stack_a);
		rotate_stack(arg->stack_a);
		
		// While aux_stack (B) is not empty and top of the aux_stack < tmp, 
		//		pop data from aux_stack and push it to the input_stack (A)
		while (arg->stack_a->size > 0 && 
			(*(int *)arg->stack_a->head->content <= tmp))
		{
			if (tmp == *(int *)arg->stack_a->head->content)
				break;
			push_stack(arg->stack_a, arg->stack_b); //pa
			print_stacks(arg);

		}
		reverse_rotate_stack(arg->stack_a);
		print_stacks(arg);

	}
}

/*
**  `./push_swap 3 2 1 0`
**	`./push_swap 3 2 one 0` -> Error
*/

int		main(int argc, char *argv[])
{
	t_checker checker_arg;

	checker_arg_init(&checker_arg);
	if (argc > 1)
	{
		if (checker_parse_arg(argc, argv, &checker_arg) != 0)
			error_exit(&checker_arg);
		
		ft_printf("Initial Position\n");
		print_stacks(&checker_arg);

		// simple_sort(&checker_arg);
		quick_sort(&checker_arg, checker_arg.max_size);
		
		ft_printf("RESULTS\n");
		print_stacks(&checker_arg);

		if (stack_is_sorted(checker_arg.stack_a) == 0 &&
			checker_arg.stack_b->head == NULL && checker_arg.stack_b->size == 0)
		{
			ft_printf("OK\n");
		}
		else
		{
			ft_printf("KO\n");
		}
		// ft_printf("RESULTS\n");
		// ft_printf("A\n");
		// ft_stack_print(checker_arg.stack_a);
		// ft_printf("======\n");
		// ft_printf("B\n");
		// ft_stack_print(checker_arg.stack_b);
		// ft_printf("======\n");
	}
	system("leaks push_swap > leaks_out.txt");
	return (0);
}
