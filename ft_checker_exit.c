/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:56:26 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/22 12:45:30 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	free_and_exit(t_checker *checker_arg)
{
	if (checker_arg->stack_a)
	{
		if (checker_arg->stack_a->head)
			ft_lstclear(&checker_arg->stack_a->head, *free);
		free(checker_arg->stack_a);
	}
	if (checker_arg->stack_b)
	{
		if (checker_arg->stack_b->head)
			ft_lstclear(&checker_arg->stack_b->head, *free);
		free(checker_arg->stack_b);
	}
	if (checker_arg->logs)
		free(checker_arg->logs);
	if (checker_arg->chunk_array)
		free(checker_arg->chunk_array);
	exit(0);
}

void	error_exit(t_checker *checker_arg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_and_exit(checker_arg);
}
