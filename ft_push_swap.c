/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:27:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/30 15:36:11 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
		quick_sort(&checker_arg, checker_arg.max_size);
		if (stack_is_sorted(checker_arg.stack_a) == 0 &&
			checker_arg.stack_b->head == NULL &&
			checker_arg.stack_b->size == 0)
		{
			ft_printf("%s", checker_arg.logs);
		}
		else
		{
			ft_printf("KO\n");
		}
	}
	print_stacks(&checker_arg);
	free_and_exit(&checker_arg);
	system("leaks push_swap > leaks_out.txt");
	return (0);
}
