/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:14:06 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/30 15:12:42 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	verify if content is valid digit, malloc integer, get the string converted
**	to integer, create linked-list node with content and push to stack.
*/

int		parse_content(char *content, t_checker *checker_arg)
{
	t_list	*new_node;
	int		tmp;
	void	*copy_content;

	if (ft_isdigit_string(content) == 0)
		error_exit(checker_arg);
	tmp = checker_atoi(content, checker_arg);
	if (!(copy_content = malloc(sizeof(int))))
		error_exit(checker_arg);
	*((int *)copy_content) = tmp;
	if (!(new_node = ft_lstnew((copy_content))))
	{
		free(copy_content);
		error_exit(checker_arg);
	}
	ft_stack_push(checker_arg->stack_a, new_node);
	return (0);
}

int		checker_parse_arg(int argc, char *argv[], t_checker *checker_arg)
{
	int		counter;

	if (find_duplicate(argc, argv) != 0)
		return (1);
	counter = 1;
	while (counter < argc)
	{
		parse_content(argv[counter], checker_arg);
		counter++;
		checker_arg->max_size++;
	}
	return (0);
}

/*
**	converts the number from string to int.
**	calls error when the number exceeds INT limit.
*/

int		checker_atoi(const char *str, t_checker *checker_arg)
{
	unsigned long	result;
	int				sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX)
			error_exit(checker_arg);
		str++;
	}
	return (int)(sign * result);
}

void	checker_arg_init(t_checker *checker_arg)
{
	char *tmp;

	tmp = "";
	if ((checker_arg->stack_a = ft_stack_init()) == NULL)
		error_exit(checker_arg);
	if ((checker_arg->stack_b = ft_stack_init()) == NULL)
		error_exit(checker_arg);
	checker_arg->max_size = 0;
	if ((checker_arg->logs = ft_strdup(tmp)) == NULL)
		error_exit(checker_arg);
}
