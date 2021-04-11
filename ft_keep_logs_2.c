/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_logs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:16:35 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/10 16:32:33 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_rra(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "rra\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	reverse_rotate_stack(arg->stack_a);
}

void	ft_stack_rrb(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "rrb\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	reverse_rotate_stack(arg->stack_b);
}

void	ft_stack_sa(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "sa\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	swap_stack(arg->stack_a);
}

void	ft_stack_sb(t_checker *arg)
{
	char	*tmp;

	tmp = ft_strjoin(arg->logs, "sb\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	swap_stack(arg->stack_b);
}
