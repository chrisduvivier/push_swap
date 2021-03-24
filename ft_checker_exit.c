/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:56:26 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/15 12:01:40 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_push_swap.h"

int free_and_exit(t_checker *checker_arg)
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
	exit(0);
}

void error_exit(t_checker *checker_arg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_and_exit(checker_arg);
}
