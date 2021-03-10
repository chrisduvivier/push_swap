

// 1 step. call checker, get to esetup a stack from the input
#include <libft.h>

// Linked-list implementation of stacks
typedef struct	s_stack
{
    size_t		size;
    t_list		*head;
    t_list		*tail;
}				t_stack;

// initialize a stuck
t_stack *ft_stack_init(void)
{
    t_stack *stack;

    if (!(stack = malloc(sizezof(t_stack))))
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

/*
**  
**
*/
int main(int argc, char *argv[])
{

    t_list *head;
}

t_list *ft_lstnew(void *content)