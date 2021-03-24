/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:07:05 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/15 20:26:02 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"

void handle_operation_suite(t_checker *checker_arg, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate_stack(checker_arg->stack_a);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_stack(checker_arg->stack_b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate_stack(checker_arg->stack_a);
		rotate_stack(checker_arg->stack_b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		reverse_rotate_stack(checker_arg->stack_a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate_stack(checker_arg->stack_b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		reverse_rotate_stack(checker_arg->stack_a);
		reverse_rotate_stack(checker_arg->stack_b);
	}
	else
	{
		free(line);
		error_exit(checker_arg);
	}
	print_stacks(checker_arg);
}

void handle_operation(t_checker *checker_arg, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_stack(checker_arg->stack_a);
	else if (ft_strcmp(line, "sb") == 0)
		swap_stack(checker_arg->stack_b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		swap_stack(checker_arg->stack_a);
		swap_stack(checker_arg->stack_b);
	}
	else if (ft_strcmp(line, "pa") == 0)
		push_stack(checker_arg->stack_b, checker_arg->stack_a);
	else if (ft_strcmp(line, "pb") == 0)
		push_stack(checker_arg->stack_a, checker_arg->stack_b);
	else
		handle_operation_suite(checker_arg, line);
}

void	print_stacks(t_checker *arg)
{
	size_t	max_num;
	size_t 	size_a;
	size_t 	size_b;
	t_list	*lst_a;
	t_list	*lst_b;

	size_a = arg->stack_a->size;
	size_b = arg->stack_b->size;
	lst_a = arg->stack_a->head;
	lst_b = arg->stack_b->head;
	max_num = arg->stack_a->size;
	if (arg->stack_b->size > max_num)
		max_num = arg->stack_b->size;
	ft_printf("-------------\n");
	ft_printf("|  A  |  B  |\n");
	ft_printf("|-----------|\n");
	while (max_num > 0)
	{
		if (size_a > 0 && size_a == max_num)
		{
			ft_printf("|  %d  |", *(int *)lst_a->content);
			lst_a = lst_a->next;
			size_a--;
		}
		else
		{
			ft_printf("|     |");
		}
		if (size_b > 0 && size_b == max_num)
		{
			ft_printf("  %d  |\n", *(int *)lst_b->content);
			lst_b = lst_b->next;
			size_b--;
		}
		else
		{
			ft_printf("     |\n");
		}
		max_num--;
	}
	ft_printf("=============\n");
}
