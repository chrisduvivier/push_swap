/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_logs_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:16:35 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/23 17:33:51 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_ra(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "ra\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	rotate_stack(arg->stack_a);
}

void	ft_stack_rb(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "rb\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	rotate_stack(arg->stack_b);
}

void	ft_stack_pa(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "pa\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	push_stack(arg->stack_b, arg->stack_a);
}

void	ft_stack_pb(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "pb\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	push_stack(arg->stack_a, arg->stack_b);
}
