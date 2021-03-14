/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:13:01 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/13 19:13:51 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"

// tmp function to check each operations in main.c
// check_operations(&checker_arg);

void    check_operations(t_checker *checker_arg)
{
	ft_stack_print(checker_arg->stack_a);
	ft_printf("==============\n");
	swap_stack(checker_arg->stack_a);
	ft_stack_print(checker_arg->stack_a);
	ft_printf("==============\n");
	swap_stack(checker_arg->stack_b);
	ft_printf("==============\n");
	push_stack(checker_arg->stack_a, checker_arg->stack_b);
	ft_printf("--- stack A ---\n");
	ft_stack_print(checker_arg->stack_a);
	ft_printf("--- stack B ---\n");
	ft_stack_print(checker_arg->stack_b);
	ft_printf("==============\n");

	push_stack(checker_arg->stack_a, checker_arg->stack_b);
	ft_printf("--- stack A ---\n");
	ft_stack_print(checker_arg->stack_a);
	ft_printf("--- stack B ---\n");
	ft_stack_print(checker_arg->stack_b);
	ft_printf("==============\n");

	rotate_stack(checker_arg->stack_a);
	ft_stack_print(checker_arg->stack_a);
	ft_printf("==============\n");
	rotate_stack(checker_arg->stack_b);
	ft_stack_print(checker_arg->stack_b);
	ft_printf("==============\n");

	reverse_rotate_stack(checker_arg->stack_a);
	ft_stack_print(checker_arg->stack_a);
	ft_printf("==============\n");

	reverse_rotate_stack(checker_arg->stack_b);
	ft_stack_print(checker_arg->stack_b);
	ft_printf("==============\n");
}