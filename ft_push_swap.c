/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:27:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/28 16:43:22 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
