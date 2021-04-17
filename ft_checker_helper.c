/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:14:06 by cduvivie          #+#    #+#             */
/*   Updated: 2021/04/17 18:31:52 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	verify if content is valid digit, malloc integer, get the string converted
**	to integer, create linked-list node with content and push to stack.
*/

int	parse_content(char *content, t_checker *checker_arg)
{
	t_list	*new_node;
	int		tmp;
	void	*copy_content;

	if (ft_isdigit_string(content) == 0)
		error_exit(checker_arg);
	tmp = checker_atoi(content, checker_arg);
	copy_content = malloc(sizeof(int));
	if (!copy_content)
		error_exit(checker_arg);
	*((int *)copy_content) = tmp;
	new_node = ft_lstnew((copy_content));
	if (!new_node)
	{
		free(copy_content);
		error_exit(checker_arg);
	}
	ft_stack_push_end(checker_arg->stack_a, new_node);
	return (0);
}

int	checker_parse_arg(int argc, char *argv[], t_checker *checker_arg)
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

int	checker_atoi(const char *str, t_checker *checker_arg)
{
	unsigned long	result;
	int				sign;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
		else
			sign = 1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX)
			error_exit(checker_arg);
		str++;
	}
	return ((int)(sign * result));
}

void	checker_arg_init(t_checker *checker_arg)
{
	char	*tmp;

	tmp = "";
	checker_arg->stack_a = ft_stack_init();
	if (checker_arg->stack_a == NULL)
		error_exit(checker_arg);
	checker_arg->stack_b = ft_stack_init();
	if (checker_arg->stack_b == NULL)
		error_exit(checker_arg);
	checker_arg->max_size = 0;
	checker_arg->logs = ft_strdup(tmp);
	if (checker_arg->logs == NULL)
		error_exit(checker_arg);
}
