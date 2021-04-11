/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:27:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/10 16:32:40 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**  `./push_swap 3 2 1 0`
**	`./push_swap 3 2 one 0` -> Error
*/

int	main(int argc, char *argv[])
{
	t_checker	checker_arg;

	checker_arg_init(&checker_arg);
	if (argc > 1)
	{
		if (checker_parse_arg(argc, argv, &checker_arg) != 0)
			error_exit(&checker_arg);
		if (stack_is_sorted(checker_arg.stack_a) != 0)
		{
			quick_sort(&checker_arg, checker_arg.max_size);
			if (stack_is_sorted(checker_arg.stack_a) == 0
				&& checker_arg.stack_b->head == NULL
				&& checker_arg.stack_b->size == 0)
			{
				ft_printf("%s", checker_arg.logs);
			}
			else
				ft_printf("KO\n");
		}
	}
	free_and_exit(&checker_arg);
	system("leaks push_swap > push_swap_leaks_out.txt");
	return (0);
}
