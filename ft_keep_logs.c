/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_logs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:16:35 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/28 16:56:57 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    ft_stack_pa(t_checker *arg)
{
	char *tmp;

	tmp = ft_strjoin(arg->logs, "pa\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	push_stack(arg->stack_b, arg->stack_a);
}

void    ft_stack_pb(t_checker *arg)
{
	char *tmp;

	tmp = ft_strjoin(arg->logs, "pa\n");
	if (!tmp)
		free_and_exit(arg);
	free(arg->logs);
	arg->logs = tmp;
	push_stack(arg->stack_a, arg->stack_b);
}