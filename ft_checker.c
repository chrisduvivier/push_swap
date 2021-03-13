

// 1 step. call checker, get to esetup a stack from the input
#include "libft/libft.h"
typedef struct	s_stack
{
    size_t		size;
    t_list		*head;
    t_list		*tail;
}				t_stack;
typedef struct	s_checker
{
    t_stack		*stack_a;
	t_stack		*stack_b;
}				t_checker;

// Linked-list implementation of stacks

// initialize a stuck
t_stack *ft_stack_init(void)
{
    t_stack *stack;

    if (!(stack = malloc(sizeof(t_stack))))
		return (NULL);
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

int			ft_isdigit_string(const char *str)
{
	long 		result;
	int			sign;

	if (*str == '-' || *str == '+')
		*str++;
	while (*str != '\0')
	{
		if (!(ft_isdigit(*str)))
			return (0);
		*str++;
	}
	return (1);
}

int		checker_atoi(const char *str)
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
			return (sign == -1) ? (0) : (-1);
		*str++;
	}
	return (int)(sign * result);
}

int	free_and_exit(t_checker *checker_arg)
{
	// TODO
	//	void	ft_lstclear(t_list **lst, void (*del)(void*))
	//	could use this function on both stack. use *free for the content as well?
	return (0); 
}

/*
**	verify if content is valid digit, malloc integer, get the string converted
**	to integer, create linked-list node with content and push to stack.
*/
int	parse_content(char *content, t_checker *checker_arg)
{
	t_list	*new_node;
	void	*copy_content;

	if (ft_isdigit_string(content) == 0)
		free_and_exit(checker_arg);
	if (!(copy_content = malloc(sizeof(int))))
		free_and_exit(checker_arg);
	*((int*)copy_content) = checker_atoi(content);
	if (!(new_node = ft_lstnew((copy_content))))
		free_and_exit(checker_arg);
	ft_stack_push(checker_arg->stack_a, new_node);
	return (0);
}

int	checker_parse_arg(int argc, char *argv[], t_checker *checker_arg)
{
	int counter;
	
	// check argc
	if (argc < 1)
	{
		ft_printf("Nothing to check. CALL EXIT.\n");
		return (1);
	}
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

/*
**  `./checker 3 2 1 0`
**	`./checker 3 2 one 0` -> Error
**
*/

int main(int argc, char *argv[])
{
	t_checker checker_arg;
	
	// Need to check if malloc OK so might need to put into 1 fonction with a global struct
	checker_arg.stack_a = ft_stack_init();
	checker_arg.stack_b = ft_stack_init();

	if (checker_parse_arg(argc, argv, &checker_arg) != 0)
	{
		//Error: free and exit 
		return (1);
	}

	//tmp check
	ft_printf("size: %d\n", checker_arg.stack_a->size);
	ft_printf("head: %d\n", *((int*)checker_arg.stack_a->head->content));
	ft_printf("tail: %d\n", *((int*)checker_arg.stack_a->tail->content));

	//check if sorted
	if (checker_is_sorted(checker_arg.stack_a) == 0)
		ft_printf("SORTED\n");
	else
		ft_printf("KO\n");

	return (0);
}