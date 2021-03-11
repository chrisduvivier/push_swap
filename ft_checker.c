

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

int	free_and_exit(t_checker *checker)
{
	// TODO
	//	void	ft_lstclear(t_list **lst, void (*del)(void*))
	//	could use this function on both stack. use *free for the content as well?
	return (0); 
}

int	parse_content(char *content, t_checker *checker)
{
	t_list	*new_node;
	char	*copy_content;

	ft_printf("%s\n", content);
	// check if valid input (digit)
	if (ft_isdigit_string(content) == 0)
	{
		ft_printf("problem with %s \n", content);
		// TODO: FREE and EXIT
		free_and_exit(checker);
		return (1);
	}

	// create node and push to stack
	// content needs to be casted to integer, and malloc is needed for the int in the node.
	// t_list	*ft_lstnew(void *content)
	if (!(copy_content = ft_strdup(content)))
	{
		ft_printf("problem with malloc ft_strdup\n");
		// TODO: FREE and EXIT
		free_and_exit(checker);
		return (1);
	}

	if (!(new_node = ft_lstnew(copy_content)))
	{
		ft_printf("problem with malloc new_node\n");
		// TODO: FREE and EXIT
		free_and_exit(checker);
		return (1);
	}

	ft_stack_push(checker->stack_a, new_node);
	return (0);
}

int	checker_parse_arg(int argc, char *argv[], t_checker *checker)
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
		// check validity of argument and append to stack_a
		if (parse_content(argv[counter], checker) != 0)
			return (1);
		counter++;
	}
	ft_printf("size: %d\n", checker->stack_a->size);
	ft_printf("head: %s\n", checker->stack_a->head->content);
	ft_printf("tail: %s\n", checker->stack_a->tail->content);
	// return OK or not
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

	return (0);
}