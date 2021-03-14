/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduvivie <cduvivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:27:36 by cduvivie          #+#    #+#             */
/*   Updated: 2021/03/14 09:32:07 by cduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1 step. call checker, get to esetup a stack from the input
#include "libft/libft.h"
#include "ft_push_swap.h"

// Linked-list implementation of stacks

// initialize a stuck
t_stack *ft_stack_init(void)
{
    t_stack *stack;

    if (!(stack = malloc(sizeof(t_stack))))
		error_exit(NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

// push to stack: append to the top (to head)
void	ft_stack_push(t_stack *stack, t_list *node)
{
	t_list *tmp;

	tmp = NULL;
	if (stack->size != 0 && stack->head != NULL)
		tmp = stack->head;
	stack->head = node;
	node->next = tmp;

	// handle tail if not set yet
	if (stack->size == 0)
		stack->tail = node;
	stack->size++;
}

// pop from stack: retrive element from top of stack (from head)
t_list *ft_stack_pop(t_stack *stack)
{
	t_list *res;

	if (stack->size == 0 || stack->head == NULL)
		return (NULL);
	res = stack->head;
	stack->head = stack->head->next;
	if (stack->head == NULL)
		stack->tail = NULL;
	stack->size--;
	return (res);
}

void	print_list_int(void *content)
{
	ft_printf("[%d]\n", *(int*)content);
}

void 	ft_stack_print(t_stack *stack)
{
	if (stack->head != NULL)
	{
		t_list *node = stack->head;
		ft_lstiter(node, *print_list_int);
		
		// tmp printing to check
		ft_printf("size: [%d] | head: [%d] | tail: %d\n", 
			stack->size,
			*(int*)stack->head->content, 
			*(int*)stack->tail->content);
		// tmp end
	}
}

int			ft_isdigit_string(const char *str)
{
	long 		result;
	int			sign;

	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
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

int	free_and_exit(t_checker *checker_arg)
{
	if (checker_arg->stack_a && checker_arg->stack_a->head)
	{
		ft_lstclear(&checker_arg->stack_a->head, *free);
	}
	if (checker_arg->stack_b && checker_arg->stack_b->head)
	{
		ft_lstclear(&checker_arg->stack_b->head, *free);
	}
	exit(0);
}

void	error_exit(t_checker *checker_arg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_and_exit(checker_arg);
}

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
	if (!(copy_content = malloc(sizeof(int))))
		error_exit(checker_arg);
	*((int*)copy_content) = tmp;
	if (!(new_node = ft_lstnew((copy_content))))
		error_exit(checker_arg);
	ft_stack_push(checker_arg->stack_a, new_node);
	return (0);
}

int	checker_parse_arg(int argc, char *argv[], t_checker *checker_arg)
{
	int counter;
	
	// check argc
	if (find_duplicate(argc, argv) != 0)
		return (1);
	counter = 1;
	// check all arg are valid inputs
	while (counter < argc)
	{
		parse_content(argv[counter], checker_arg);
		counter++;
	}
	// return OK or not
	return (0);
}

int	checker_is_sorted(t_stack *stack)
{
	t_list 	*cursor;
	int		number;
	int		next;

	cursor = stack->head;
	while (cursor != NULL)
	{
		number = *((int*)cursor->content);
		if (cursor->next != NULL)
		{
			next = *((int*)cursor->next->content);
			if (number > next)
				return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

void	handle_operation_suite(t_checker *checker_arg, char *line)
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
}

void	handle_operation(t_checker *checker_arg, char *line)
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

int		read_user_input(t_checker *checker_arg)
{
	char 	*line;
	int		ret;

	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		// ft_printf("gnl:[%d] line:[%s]\n", ret, line);
		if (line && (ft_strcmp(line, "") == 0))
		{
			// ft_printf("empty string call exit\n");
			return (0);
		}
		handle_operation(checker_arg, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
		ft_stack_print(checker_arg->stack_a);
	}
	if (ret < 0)
		error_exit(checker_arg);
	return (0);
}

/*
**  `./checker 3 2 1 0`
**	`./checker 3 2 one 0` -> Error
*/
int main(int argc, char *argv[])
{
	t_checker 	checker_arg;
	
	// Need to check if malloc OK so might need to put into 1 fonction with a global struct
	checker_arg.stack_a = ft_stack_init();
	checker_arg.stack_b = ft_stack_init();
	if (argc > 1)
	{
		if (checker_parse_arg(argc, argv, &checker_arg) != 0)
			error_exit(&checker_arg);
		
		// read user input
		read_user_input(&checker_arg);


		//check if sorted
		if (checker_is_sorted(checker_arg.stack_a) == 0 && 
			!checker_arg.stack_b->head && checker_arg.stack_b->size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	system("leaks a.out > leaks_out.txt");
	return (0);
}