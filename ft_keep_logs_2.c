/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_logs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:16:35 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/30 15:13:57 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_stack_rra(t_checker *arg)
{
	char *tmp;

	tmp = ft_strjoin(arg->logs, "rra\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	reverse_rotate_stack(arg->stack_a);
}

void	ft_stack_rrb(t_checker *arg)
{
	char *tmp;

	tmp = ft_strjoin(arg->logs, "rrb\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	reverse_rotate_stack(arg->stack_b);
}
