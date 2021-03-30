/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:27:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/30 01:54:03 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		read_user_input(t_checker *checker_arg)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (line && (ft_strcmp(line, "") == 0))
		{
			free(line);
			return (0);
		}
		handle_operation(checker_arg, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (ret < 0)
		error_exit(checker_arg);
	return (0);
}

/*
**  `./checker 3 2 1 0`
**	`./checker 3 2 one 0` -> Error
*/

int		main(int argc, char *argv[])
{
	t_checker checker_arg;

	checker_arg_init(&checker_arg);
	if (argc > 1)
	{
		if (checker_parse_arg(argc, argv, &checker_arg) != 0)
		{
			error_exit(&checker_arg);
		}
		read_user_input(&checker_arg);
		if (stack_is_sorted(checker_arg.stack_a) == 0 &&
			!(checker_arg.stack_b->head) && checker_arg.stack_b->size == 0)
		{
			ft_printf("OK\n");
		}
		else
			ft_printf("KO\n");
	}
	system("leaks checker > leaks_out.txt");
	return (0);
}
